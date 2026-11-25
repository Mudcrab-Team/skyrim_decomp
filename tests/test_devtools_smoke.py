import json
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

from devtools.client import BUILD, IMAGE_SHA256, INVENTORY, RpcError, Session
from devtools.smoke import Counts, exercise, run


SESSION_ID = "0" * 32


class ToySocket:
    def __init__(self, events=None):
        self.events = [] if events is None else events
        self.methods = []
        self.response = None
        self.epoch = 0
        self.seq = 0
        self.load_ok = True
        self.menu = None
        self.movie = False
        self.wrong_id = False
        self.wrong_image = False
        self.reject = None

    async def send(self, text):
        request = json.loads(text)
        method, params = request["method"], request["params"]
        self.methods.append((method, params))
        self.response = {"jsonrpc": "2.0", "id": request["id"] + self.wrong_id}
        if self.reject is not None:
            self.response["error"] = {"code": self.reject, "message": "Toy failure"}
            return
        if method == "Session.getInfo":
            value = {
                "protocol": 1, "build": BUILD,
                "imageSha256": "wrong" if self.wrong_image else IMAGE_SHA256,
                "sessionId": SESSION_ID, "dataLoaded": True,
                "capabilities": ["loadFixture", "inventory", "tapTab", "skseVersionQuery"],
            }
        elif method == "Session.loadFixture" and params == {"alias": "fixture"}:
            self.epoch = 1
            value = {"loadEpoch": self.epoch}
        elif method == "Events.snapshot":
            self.seq += 1
            value = {
                "seq": self.seq, "loadEpoch": self.epoch,
                "loadCompleted": bool(self.epoch), "loadSucceeded": bool(self.epoch and self.load_ok),
                "mainMenuOpen": not self.epoch, "playable": bool(self.epoch and self.load_ok),
                "inventoryOpen": self.menu == INVENTORY,
                "inventoryMovieReady": self.menu == INVENTORY and self.movie,
                "consoleOpen": self.menu == "Console", "consoleMovieReady": self.menu == "Console" and self.movie,
            }
            self.movie = self.menu is not None
        elif params.get("loadEpoch") != self.epoch:
            raise AssertionError("Mutation used the wrong load epoch")
        elif method == "UI.openMenu":
            self.menu = params["name"]
            self.movie = False
            value = {"accepted": True}
        elif method == "UI.closeMenu" and self.menu == params["name"]:
            self.menu = None
            value = {"accepted": True}
        elif method == "Input.dispatchKey" and self.menu == INVENTORY and self.movie:
            assert params["key"] == "Tab" and params["phase"] == "tap"
            self.menu = None
            value = {"accepted": True}
        elif method == "Console.execute" and self.menu == "Console" and self.movie:
            assert params["command"] == "GetSKSEVersion"
            value = {"observed": True, "version": "2.3.1"}
        else:
            raise AssertionError(f"Unexpected request {method}")
        self.response["result"] = value

    async def recv(self):
        return json.dumps(self.response)

    async def close(self):
        self.events.append("socket-close")


class ToyHost:
    local_port = 48681

    def __init__(self, start_fails=False, stop_phase="stopped"):
        self.events = []
        self.start_fails = start_fails
        self.stop_phase = stop_phase
        self.returncode = None

    async def command(self, action):
        self.events.append(action)
        return {"sessionId": SESSION_ID, "port": 48682, "token": "a" * 64}

    async def wait_ready(self, session_id):
        assert session_id == SESSION_ID
        self.events.append("ready")
        if self.start_fails:
            raise RuntimeError("Toy preflight rejected the launch")

    async def tunnel(self, port):
        assert port == 48682
        self.events.append("tunnel")
        return self

    async def stop(self, session_id):
        assert session_id == SESSION_ID
        self.events.append("stop")
        return {"phase": self.stop_phase, "exitCode": 0, "reason": ""}

    def terminate(self):
        self.events.append("tunnel-stop")

    async def wait(self):
        self.returncode = 0


class DevToolsSmokeTest(unittest.IsolatedAsyncioTestCase):
    async def test_inventory_cycles_wait_for_movie_and_send_each_mutation_once(self):
        socket = ToySocket()
        counts = Counts()
        await exercise(Session(socket, SESSION_ID), counts, 3)
        self.assertEqual(counts, Counts(sessions=1, loaded=1, inventory_cycles=3, input_taps=1, console_queries=1))
        names = [method for method, _ in socket.methods]
        self.assertEqual(names.count("Session.loadFixture"), 1)
        self.assertEqual(names.count("UI.openMenu"), 5)
        for i, method in enumerate(names):
            if method == "UI.openMenu":
                self.assertEqual(names[i + 1:i + 3], ["Events.snapshot", "Events.snapshot"])
        self.assertIsNone(socket.menu)

    async def test_load_failure_stops_before_menu_operations(self):
        socket = ToySocket()
        socket.load_ok = False
        counts = Counts()
        with self.assertRaisesRegex(RuntimeError, "failed save load"):
            await exercise(Session(socket, SESSION_ID), counts, 3)
        self.assertEqual(counts, Counts(sessions=1))
        self.assertFalse(any(method.startswith("UI.") for method, _ in socket.methods))

    async def test_stale_epoch_is_detected_before_any_menu_operation(self):
        socket = ToySocket()
        session = Session(socket, SESSION_ID)
        await session.load()
        socket.epoch += 1
        with self.assertRaisesRegex(RuntimeError, "Load epoch changed"):
            await session.snapshot()

    async def test_wrong_response_id_invalidates_connection(self):
        socket = ToySocket()
        socket.wrong_id = True
        session = Session(socket, SESSION_ID)
        with self.assertRaisesRegex(RuntimeError, "Unexpected JSON-RPC response"):
            await session.info()
        with self.assertRaisesRegex(RuntimeError, "no longer usable"):
            await session.info()
        self.assertEqual(len(socket.methods), 1)

    async def test_ui_timeout_invalidates_connection(self):
        socket = ToySocket()
        socket.reject = -32008
        session = Session(socket, SESSION_ID)
        with self.assertRaises(RpcError) as caught:
            await session.snapshot()
        self.assertEqual(caught.exception.code, -32008)
        with self.assertRaisesRegex(RuntimeError, "no longer usable"):
            await session.snapshot()

    async def test_identity_mismatch_prevents_mutations(self):
        socket = ToySocket()
        socket.wrong_image = True
        with self.assertRaisesRegex(RuntimeError, "identity mismatch"):
            await exercise(Session(socket, SESSION_ID), Counts(), 3)
        self.assertEqual(socket.methods, [("Session.getInfo", {})])

    async def test_session_only_stops_before_closing_transport(self):
        host = ToyHost()
        socket = ToySocket(host.events)

        async def connect(uri, **kwargs):
            self.assertEqual(uri, "ws://127.0.0.1:48681/rpc")
            self.assertEqual(kwargs["additional_headers"], {"Authorization": "Bearer " + "a" * 64})
            return socket

        counts = Counts()
        await run(host, connect, counts, 3, session_only=True)
        self.assertEqual(counts, Counts(sessions=1, loaded=1, clean_stops=1))
        self.assertEqual(host.events, ["start", "ready", "tunnel", "stop", "socket-close", "tunnel-stop"])

    async def test_startup_failure_still_requests_stop(self):
        host = ToyHost(start_fails=True, stop_phase="failed")

        async def connect(*args, **kwargs):
            self.fail("Refused startup must never connect")

        with self.assertRaisesRegex(RuntimeError, "Toy preflight"):
            await run(host, connect, Counts(), 3, session_only=True)
        self.assertEqual(host.events, ["start", "ready", "stop"])

    async def test_crash_is_reported_after_socket_and_tunnel_cleanup(self):
        host = ToyHost(stop_phase="crashed")
        socket = ToySocket(host.events)

        async def connect(*args, **kwargs):
            return socket

        counts = Counts()
        with self.assertRaisesRegex(RuntimeError, "did not stop cleanly .*crashed"):
            await run(host, connect, counts, 3, session_only=True)
        self.assertEqual(counts, Counts(sessions=1, loaded=1))
        self.assertEqual(host.events[-3:], ["stop", "socket-close", "tunnel-stop"])
