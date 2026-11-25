"""Client for the single-controller Skyrim DevTools RPC session."""

import asyncio
import json


BUILD = "sse-steam-1-7-104"
IMAGE_SHA256 = "846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f"
INVENTORY = "InventoryMenu"


class RpcError(RuntimeError):
    def __init__(self, code, message):
        super().__init__(f"RPC {code} · {message}")
        self.code = code


class Session:
    def __init__(self, socket, session_id):
        self.socket = socket
        self.session_id = session_id
        self._next_id = 0
        self._lock = asyncio.Lock()
        self._failed = False
        self._seq = 0
        self.epoch = None

    async def call(self, method, **params):
        async with self._lock:
            if self._failed:
                raise RuntimeError("RPC connection is no longer usable")
            self._next_id += 1
            request = dict(jsonrpc="2.0", id=self._next_id, method=method, params=params)
            try:
                async with asyncio.timeout(6):
                    await self.socket.send(json.dumps(request))
                    response = json.loads(await self.socket.recv())
                if (
                    not isinstance(response, dict)
                    or response.get("jsonrpc") != "2.0"
                    or type(response.get("id")) is not int
                    or response["id"] != self._next_id
                    or ("result" in response) == ("error" in response)
                ):
                    raise RuntimeError("Unexpected JSON-RPC response")
                if "error" in response:
                    error = response["error"]
                    if not isinstance(error, dict) or type(error.get("code")) is not int:
                        raise RuntimeError("Malformed JSON-RPC error")
                    if error["code"] == -32008:
                        self._failed = True
                    raise RpcError(error["code"], error.get("message", "Request failed"))
                return response["result"]
            except RpcError:
                raise
            except BaseException:
                self._failed = True
                raise

    async def info(self):
        info = await self.call("Session.getInfo")
        if (
            info["protocol"] != 1
            or info["build"] != BUILD
            or info["imageSha256"] != IMAGE_SHA256
            or info["sessionId"] != self.session_id
        ):
            raise RuntimeError("Protocol, image or session identity mismatch")
        return info

    async def load(self):
        result = await self.call("Session.loadFixture", alias="fixture")
        self.epoch = result["loadEpoch"]

    async def snapshot(self):
        state = await self.call("Events.snapshot")
        if state["seq"] <= self._seq:
            raise RuntimeError("UI observation did not advance")
        self._seq = state["seq"]
        if self.epoch is not None and state["loadEpoch"] != self.epoch:
            raise RuntimeError("Load epoch changed during the scenario")
        if state["loadCompleted"] and not state["loadSucceeded"]:
            raise RuntimeError("The game reported a failed save load")
        return state

    async def set_menu(self, menu, opening):
        verb = "openMenu" if opening else "closeMenu"
        return await self.call(f"UI.{verb}", name=menu, loadEpoch=self.epoch)

    async def tap_tab(self):
        return await self.call("Input.dispatchKey", key="Tab", phase="tap", loadEpoch=self.epoch)

    async def console_version(self):
        return await self.call("Console.execute", command="GetSKSEVersion", loadEpoch=self.epoch)


async def observe(read, predicate, label, timeout):
    """Poll observations so a timed-out mutation is never submitted twice."""
    deadline = asyncio.get_running_loop().time() + timeout
    while True:
        state = await read()
        if predicate(state):
            return state
        if asyncio.get_running_loop().time() >= deadline:
            raise TimeoutError(f"{label} timed out")
        await asyncio.sleep(0.1)
