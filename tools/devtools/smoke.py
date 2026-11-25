#!/usr/bin/env python3
"""Launch, drive and close the Windows offline Skyrim fixture from the Mac."""

import argparse
import asyncio
import base64
from dataclasses import asdict, dataclass
import json
from pathlib import Path
import re
import subprocess

from .client import INVENTORY, Session, observe


ACTIVE = {"starting", "running"}


@dataclass
class Counts:
    sessions: int = 0
    loaded: int = 0
    inventory_cycles: int = 0
    input_taps: int = 0
    console_queries: int = 0
    clean_stops: int = 0


class WindowsHost:
    def __init__(self, config):
        destination = config["sshDestination"]
        if not isinstance(destination, str) or not destination or destination.startswith("-"):
            raise ValueError("Set an SSH destination or alias in the local configuration")
        self.ssh = ["ssh", "-o", "BatchMode=yes", "-o", "ConnectTimeout=6"]
        if path := config.get("sshConfig"):
            self.ssh += ["-F", str(Path(path).expanduser())]
        self.destination = destination
        self.local_port = config.get("localPort", 48681)
        if type(self.local_port) is not int or not 1024 <= self.local_port <= 65535:
            raise ValueError("Local port must be between 1024 and 65535")

    async def command(self, action, session_id=""):
        if action not in {"start", "status", "stop"} or (session_id and not re.fullmatch("[a-f0-9]{32}", session_id)):
            raise ValueError("Invalid Windows session operation")
        script = rf"& (Join-Path $env:USERPROFILE '.local\skyrim-devtools\host.ps1') {action} {session_id}"
        encoded = base64.b64encode(script.encode("utf-16-le")).decode("ascii")
        process = await asyncio.create_subprocess_exec(
            *self.ssh, "-T", self.destination, "powershell", "-NoProfile", "-NonInteractive",
            "-ExecutionPolicy", "RemoteSigned",
            "-EncodedCommand", encoded, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL,
        )
        try:
            async with asyncio.timeout(12):
                data, _ = await process.communicate()
        finally:
            if process.returncode is None:
                process.kill()
                await process.wait()
        if process.returncode:
            raise RuntimeError(f"Windows host {action} failed")
        try:
            return json.loads(data)
        except ValueError as error:
            raise RuntimeError(f"Invalid response from Windows host {action}") from error

    async def wait_ready(self, session_id):
        async def read():
            state = await self.command("status", session_id)
            if state["phase"] not in ACTIVE:
                raise RuntimeError(f"Windows host ended during startup ({state['phase']}, {state['reason']})")
            return state

        return await observe(read, lambda state: state["phase"] == "running", "Windows launch", 40)

    async def stop(self, session_id):
        await self.command("stop", session_id)

        async def read():
            return await self.command("status", session_id)

        return await observe(read, lambda state: state["phase"] not in ACTIVE, "Windows shutdown", 22)

    async def tunnel(self, port):
        if type(port) is not int or not 1024 <= port <= 65535:
            raise ValueError("Windows host returned an invalid port")
        return await asyncio.create_subprocess_exec(
            *self.ssh, "-NT", "-o", "ExitOnForwardFailure=yes",
            "-L", f"127.0.0.1:{self.local_port}:127.0.0.1:{port}", self.destination,
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
        )


async def exercise(session, counts, cycles, session_only=False):
    if session_only:
        needed = {"loadFixture"}
    else:
        needed = {"loadFixture", "inventory", "tapTab", "skseVersionQuery"}
    info = await observe(session.info, lambda state: state["dataLoaded"], "Game data", 45)
    if not needed <= set(info["capabilities"]):
        raise RuntimeError("The host lacks required capabilities")
    counts.sessions += 1

    await observe(session.snapshot, lambda state: state["mainMenuOpen"], "Main menu", 30)
    await session.load()
    await observe(session.snapshot, lambda state: state["playable"], "Save load", 45)
    counts.loaded += 1
    if session_only:
        return

    async def open_inventory():
        await session.set_menu(INVENTORY, True)
        await observe(
            session.snapshot, lambda state: state["inventoryOpen"] and state["inventoryMovieReady"],
            "Inventory movie", 8,
        )

    async def expect_inventory_closed():
        await observe(session.snapshot, lambda state: not state["inventoryOpen"], "Inventory close", 8)

    for _ in range(cycles):
        await open_inventory()
        await session.set_menu(INVENTORY, False)
        await expect_inventory_closed()
        counts.inventory_cycles += 1

    await open_inventory()
    await session.tap_tab()
    await expect_inventory_closed()
    counts.input_taps += 1

    await session.set_menu("Console", True)
    await observe(
        session.snapshot, lambda state: state["consoleOpen"] and state["consoleMovieReady"],
        "Console movie", 8,
    )
    result = await session.console_version()
    if result != {"observed": True, "version": "2.3.1"}:
        raise RuntimeError("Console did not report the expected SKSE version")
    counts.console_queries += 1
    await session.set_menu("Console", False)
    await observe(session.snapshot, lambda state: not state["consoleOpen"], "Console close", 8)


async def connect(connect_ws, local_port, token):
    uri = f"ws://127.0.0.1:{local_port}/rpc"
    deadline = asyncio.get_running_loop().time() + 45
    while True:
        try:
            return await connect_ws(
                uri, additional_headers={"Authorization": f"Bearer {token}"},
                compression=None, proxy=None, open_timeout=2, max_size=8192,
            )
        except (OSError, TimeoutError):
            if asyncio.get_running_loop().time() >= deadline:
                raise TimeoutError("Windows plugin endpoint did not start") from None
            await asyncio.sleep(0.3)


async def run(host, connect_ws, counts, cycles, session_only):
    bootstrap = await host.command("start")
    session_id = bootstrap["sessionId"]
    token = bootstrap["token"]
    tunnel = None
    socket = None
    try:
        if not re.fullmatch("[a-f0-9]{32}", session_id) or not re.fullmatch("[a-f0-9]{64}", token):
            raise RuntimeError("Invalid session bootstrap")
        await host.wait_ready(session_id)
        tunnel = await host.tunnel(bootstrap["port"])
        socket = await connect(connect_ws, host.local_port, token)
        await exercise(Session(socket, session_id), counts, cycles, session_only)
    finally:
        try:
            stopped = await host.stop(session_id)
            if stopped["phase"] == "stopped" and stopped["exitCode"] == 0:
                counts.clean_stops += 1
            elif stopped["phase"] not in {"failed", "cancelled"} or counts.loaded:
                raise RuntimeError(f"Windows game did not stop cleanly ({stopped['phase']}, {stopped['reason']})")
        finally:
            try:
                if socket is not None:
                    await socket.close()
            finally:
                if tunnel is not None and tunnel.returncode is None:
                    tunnel.terminate()
                    await tunnel.wait()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config", required=True, type=Path)
    parser.add_argument("--cycles", type=int, default=5)
    parser.add_argument("--session-only", action="store_true")
    options = parser.parse_args()
    if not 1 <= options.cycles <= 100:
        parser.error("--cycles must be between 1 and 100")

    try:
        from websockets.asyncio.client import connect as connect_ws
    except ImportError:
        parser.error("Install the Python dependencies in requirements.txt")
    from websockets.exceptions import WebSocketException

    counts = Counts()
    result = 0
    try:
        config = json.loads(options.config.read_text())
        asyncio.run(run(WindowsHost(config), connect_ws, counts, options.cycles, options.session_only))
    except (OSError, ValueError, RuntimeError, KeyError, WebSocketException) as error:
        print(f"FAIL {error}")
        result = 1
    except KeyboardInterrupt:
        print("FAIL interrupted")
        result = 1
    print(json.dumps(asdict(counts), sort_keys=True))
    return result


if __name__ == "__main__":
    raise SystemExit(main())
