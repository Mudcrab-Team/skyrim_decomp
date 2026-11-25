# Skyrim DevTools

The Mac runner starts an SKSE session on the Windows test desktop, loads a disposable save,
and waits for the game to report that it is playable. It opens Inventory, waits for the
game's UI to report both the open menu and its Scaleform root, and closes it. After the
configured number of cycles it checks one Tab tap in Inventory and reads the observed
result of the read-only GetSKSEVersion console command. The host records a clean stop
only when the owned process exits with code zero after a stop request.

## Windows build

Target Windows x64 with Visual Studio 2022, CMake, and these local source checkouts.

- COMMUNITY(alandtse/CommonLibSSE-NG@7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a, GPL-3.0-or-later).
  The plugin calls the pinned community headers and linked library. See the upstream
  [source and notices](https://github.com/alandtse/CommonLibSSE-NG/tree/7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a)
  and [linking exceptions](https://github.com/alandtse/CommonLibSSE-NG/blob/7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a/EXCEPTIONS.md).
- COMMUNITY(yhirose/cpp-httplib@7800c3dc5b33285cbb18baa5998de4ff7ef63515, MIT).
  The transport includes the upstream [WebSocket server header](https://github.com/yhirose/cpp-httplib/tree/7800c3dc5b33285cbb18baa5998de4ff7ef63515).
- COMMUNITY(nlohmann/json@55f93686c01528224f448c19128836e7df245f72, MIT).
  [JSON for Modern C++ v3.12.0](https://github.com/nlohmann/json/tree/55f93686c01528224f448c19128836e7df245f72).
- The Python client uses [websockets 16.0](https://github.com/python-websockets/websockets/tree/16.0) (BSD-3-Clause).

Install directxmath, directxtk, fmt, nlohmann-json, rapidcsv and spdlog with the
x64-windows-static-md triplet of [vcpkg 2026.10.16](https://github.com/microsoft/vcpkg/tree/5d4a3dc90c0b3773f3bac81bf41297b54328f471).
Set the shell variables below to your private paths. The Release build selects CommonLib's AE
configuration. Keep the library, dependency tree, generated DLL, and PDB under the owner's
private .local tree. The linked DLL is for local testing.

~~~powershell
cmake -S tools/devtools/native -B "$scratch/build" -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE="$deps/vcpkg/scripts/buildsystems/vcpkg.cmake" -DVCPKG_MANIFEST_MODE=OFF -DVCPKG_TARGET_TRIPLET=x64-windows-static-md -DCOMMONLIB_SOURCE="$deps/commonlib" -DHTTPLIB_SOURCE="$deps/httplib"
cmake --build "$scratch/build" --config Release --parallel 6
~~~

## Offline desktop setup

On the interactive test account, use %USERPROFILE%\.local\skyrim-devtools as the
scratch root with the following layout.

- **host.ps1** from this directory. Use the same account for SSH and the interactive Windows task.
- **game/** with an owner-local stock copy of the executable and assets at the
  [repository target pin](../../builds/target.json). Stage the official
  [SKSE 2.3.1 Steam release](https://skse.silverlock.org/) in this copy. In its Data/SKSE/Plugins
  directory stage SkyrimDevTools.dll and the matching
  [Address Library](https://www.nexusmods.com/skyrimspecialedition/mods/32444) table
  versionlib-1-7-104-0.bin. Use a clean load order and one plugin DLL.
- **profile/** with private Skyrim.ini and SkyrimPrefs.ini copies and an empty Saves subdirectory.
  Set [General] sLocalSavePath=Saves\ in Skyrim.ini. Set bSaveOnPause, bSaveOnRest, bSaveOnTravel
  and bSaveOnWait to 0 in SkyrimPrefs.ini. On this test account only, point the Documents
  My Games\Skyrim Special Edition junction to the private profile so logs and saves land there.
- **fixture.ess** with a locally owned vanilla save that loads with that load order and starts
  in a quiet location. The launcher copies it into the scratch save directory before launch.
- **config.json** with {"port":48682,"cloudSyncDisabled":true} after disabling Steam Cloud for Skyrim.

Put Steam in [Offline Mode](https://help.steampowered.com/en/faqs/view/0E18-319B-E34B-B2C8)
and leave the test desktop logged in and unlocked. Run the setup command once as that user.
The task uses the interactive token so that the game's window can receive input.
Preflight reports an inactive or locked desktop, unavailable Steam, unconfirmed Offline Mode
or unconfirmed Steam Cloud settings before it starts the loader.

~~~powershell
powershell -NoProfile -ExecutionPolicy RemoteSigned -File "$scratch/host.ps1" install-task
~~~

## Run from the Mac

Use the existing key-based SSH connection. In an ignored Mac configuration file, set
sshDestination to the SSH alias, optionally set sshConfig to the SSH config file, and set
localPort if 48681 is occupied. Install requirements.txt into a local Python 3.13 environment.

~~~sh
python3.13 -m tools.devtools.smoke --config .local/devtools-mac.json --cycles 5
python3.13 -m unittest discover -s tests -p test_devtools_smoke.py
~~~

Use --session-only to exercise launch, handshake, fixture load and shutdown. The runner
prints aggregate counts. The private Windows runs directory holds the launcher status
and RPC transcript. The profile holds the game and loader logs.

Protocol 1 uses one JSON-RPC 2.0 call with a numeric ID per WebSocket text message at /rpc.
The locked-down listener binds to Windows loopback, authenticates a per-run bearer token,
rejects browser origins and holds a single controller lease. SSH forwards loopback to
loopback. Session.getInfo, Session.loadFixture, Session.close, Events.snapshot,
UI.openMenu, UI.closeMenu, Input.dispatchKey and Console.execute are the supported calls.
Menu and input mutations carry the current load epoch. The snapshot sequence counts observed
UI tasks. Native event streaming, menu locators and equipment assertions belong to later work.

## Prior art reviewed

- [SkyrimNet Game Plugin](https://github.com/FatelessAI/SkyrimNet-GamePlugin/tree/c65a32e1b58bf723b3bd003a305cfa79367ff6e9)
  integrates an in-process Skyrim mod with a companion AI engine. Its custom license restricts
  redistribution. The MIT Papyrus API covers integrations with that mod.
- [Skyrim CrowdControl](https://github.com/Superxwolf/Skyrim-CrowdControl/tree/edb26e4e1d17c9196ea9620837d98bd6f3e8b111)
  uses an MIT-licensed connector and Papyrus event handling for Warp World TCP commands.
  It initiates an outbound connection and uses a different command protocol.
- [NL_CMD](https://github.com/MrOctopus/nl_cmd/tree/e13d3c7f0e45fbc6ca8efdffb391a3261a3a3e82)
  provides MIT-licensed Papyrus console registration and execution with an additional game plugin.
- [Skyrim Platform](https://github.com/skyrim-multiplayer/skymp/tree/2849e676fe008925384b26f34476e382a30bd877/skyrim-platform)
  is a GPLv3 JavaScript and TypeScript runtime with a broader scripting surface and Chromium integration.
- [SkyLink AI](https://github.com/maksidze/Skyrim-MCP/tree/82a0a80d31ae7d2254d40c129650d1e260da38a2)
  states MIT in its README. It uses a named pipe and a separate .NET MCP bridge for many game actions.

These projects were reviewed as source references. The runner uses the pinned libraries above
directly and includes original host, protocol, and game adapter code.
