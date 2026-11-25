# Milestone: Skyrim DevTools

Give agents and scripts a remote debugging interface for Skyrim SE, in the style of Chrome DevTools
Protocol. A Mac script drives the owner’s offline Windows game, waits for game events and checks what
happened. Six workstreams (A to F) take it from one menu round trip to repeatable playtests.

**Owner: Maintainer** · open to contributors (comment to join).

Tracking issue: [Milestone: Skyrim DevTools](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1224).
The later renderer work follows [Rendering 1:1](rendering.md).

## Goal and scope

- **Goal.** From the Mac, an agent starts an offline session on the Windows PC, loads a disposable
  save, clicks menus and equips an inventory item, walks, activates a world object and talks to an NPC,
  lands a melee hit, runs a console command and captures a screenshot. A scenario asserts each
  outcome and can replay from a clean fixture.
- **Target.** The owner’s Steam x86-64 build `sse-steam-1-7-104`, version `1.7.104.0`, and the
  installed-image SHA-256 in [builds/target.json](../../builds/target.json). A stock executable on disk,
  an official SKSE install, one local test plugin, an offline profile and disposable save copies are
  the baseline. The maintainer approved unattended launches on this PC in that setup.
- **Later.** Add an opt-in `Render` domain for a frame capture, pass order and bound targets, and
  per-pass lights. Use the existing frame ID and the renderer, pass and light ownership in
  [Rendering 1:1](rendering.md).
- **Out of scope.** Online play, anti-cheat, DRM, other game builds, a generic memory or process
  debugger, and whole-engine deterministic simulation.

## Why it matters

1. **Automatic playtesting.** One scenario checks a real menu selection, movement, interaction and hit
   in retail gameplay. A failure identifies the last observed state and the action that diverged.
2. **Runtime-pilot automation.** Re-run the same bounded scenario for the stock baseline and an
   approved local debugger or profiling probe. The parked runtime plan gates broader instrumentation
   on a manual pilot that changes a concrete drafting or binding decision. A working playtest harness
   can ship independently for its own acceptance test.
3. **exelink smoke tests.** Re-run the same scenario on stock and on an owner-local exelink output
   that passes the offline placement report and full retail SHA-256. Record the source revision and
   the relink manifest so a byte-identical output still exercises the build-and-launch pipeline.
   A differing image stops at offline diagnostics under this plan. [exelink](../exelink.md)
4. **Retail facts for Mudcrab.** Report reproducible black-box behavior such as menu input gating,
   inventory selection, activation range or hit outcomes. A fact needs a build, fixture description,
   observed inputs and outputs, uncertainty and an exposure declaration. Proposed transfer starts
   `UNREVIEWED` and goes through the existing review. [Research boundary](../clean-room.md)

## Rules that do not change

- Follow [AGENTS.md](../../AGENTS.md), [LEGAL.md](../../LEGAL.md), [PROVENANCE.md](../../PROVENANCE.md)
  and [clean-room.md](../clean-room.md). Keep executables, generated objects, SDKs, Address Library
  tables, the binding ledger, saves, screenshots, movie trees, raw traces, console output and frame
  captures under the owner’s `.local/` paths. Local game logs and test-profile save scratch belong
  there too. Send agents sanitized assertion outcomes. Any cloud use of game-derived material
  requires the explicit authorization and service-terms assessment in AGENTS.md. Share reviewed
  factual metadata, aggregate results and synthetic fixtures.
- Publish original protocol, client, runner, test and adapter source with the applicable notices and
  provenance. The contributor function PR path stays scoped to `reconstruction/**` and
  `docs/cookbook-notes/**`. Use the infrastructure route for tooling. Record community-derived
  declarations as `COMMUNITY(<owner>/<repo>@<pin>, <SPDX>)` and retain required per-file notices.
- A runtime observation can validate a particular call or layout property. A function earns
  `matched` through the ordinary two-host byte match and admitted review. Record community names
  with their source label and preserve unresolved aliases. [Verification](../verification.md)

## Protocol

A versioned schema defines commands, results, errors and events. Use JSON-RPC 2.0, one UTF-8 JSON
message per WebSocket message. Reuse the existing key-based Mac-to-PC SSH link with local port
forwarding to the Windows loopback listener. The plugin opens only in a dedicated test session.
Require a short-lived per-session token, reject browser origins and hold one controller lease.
The stock game stays offline. A Windows named pipe with a user ACL can be a later local transport
if needed. [JSON-RPC 2.0](https://www.jsonrpc.org/specification) ·
[Chrome DevTools Protocol](https://chromedevtools.github.io/devtools-protocol/) ·
[Windows verifier link](../windows-verifier-host.md)

| Domain | First methods | Observations |
|---|---|---|
| `Session` | `getInfo`, `loadFixture`, `cancel`, `close` | Protocol version, build, image identity, capabilities, session ID, state and load epoch. Load accepts a configured fixture alias. |
| `Input` | `dispatchKey`, `dispatchPointer`, `releaseAll` | Key/button phase, input context and update applied. Held input expires or is cleared on disconnect, load and abort. |
| `UI` | `listMenus`, `openMenu`, `closeMenu`, `getTree`, `click` | Menu open/close, movie ready, focus, selection and equipped state. Resolve clicks by menu and locator, with a coordinate fallback. |
| `Console` | `execute` | Accepted action, terminal action status and bounded output when supported. Start with a verified read-only command allowlist and add deliberate fixture-only commands as needed. |
| `Player` | `getState`, `look`, `move`, `stop` | Position in game units, heading, cell and locomotion state. Walking uses normal input and collision. |
| `World` | `getCrosshairRef`, `queryNearby`, `activate` | Bounded queries over loaded references, with kind, distance and an opaque handle. Activation targets the current verified focus and observes the interaction. |
| `Combat` | `attack`, `block`, `getState` | Attack started, hit with source and target, and a health delta when applicable. Attack uses normal controls. |
| `Capture` | `screenshot` | Artifact ID, dimensions, format and frame ID for a PNG written on the PC under `.local/`. |
| `Events` | `subscribe`, `snapshot`, `resync` | Ordered sequence, session ID, load epoch, update counter and frame ID when available. A sequence gap is explicit. |
| `Time` (later) | `getState`, `setScale`, `step` | Record calendar scale and measured simulation updates separately. Advertise stepping only after verifying pause and update semantics. |
| `Render` (later) | `captureFrame`, `getPasses`, `getLights` | Frame-bound artifact and bounded pass/light summaries. Enable only verified renderer capabilities. |

`Session.getInfo` negotiates the major version and capabilities. Methods validate parameters,
capability, load state and epoch before dispatch. Queries return owned snapshots. Long actions
acknowledge with an action ID and emit `Events.actionFinished` with success, failure or timeout and
the applied update when known. Native notifications include `UI.menuOpened`, `UI.movieReady`,
`UI.menuClosed` and `Combat.hit`. Subscription returns a snapshot and cursor together. Clients subscribe before
dispatch and can correlate a terminal event even if it arrives before the command response.
Loading invalidates object handles and menu locators from the previous epoch. Closing and
reopening a menu also invalidates its locators. Keep mutation order serial, cap request sizes,
in-flight work and event buffering, and return typed errors for stale handles, missing capabilities,
busy state and timeouts. If an event gap or disconnect obscures a mutation’s outcome, resync or
reload the fixture before proceeding.

```jsonl
{"jsonrpc":"2.0","id":7,"method":"UI.openMenu","params":{"name":"InventoryMenu","loadEpoch":2}}
{"jsonrpc":"2.0","id":7,"result":{"actionId":"a7"}}
{"jsonrpc":"2.0","method":"UI.movieReady","params":{"actionId":"a7","sessionId":"s1","seq":41,"loadEpoch":2,"update":208,"name":"InventoryMenu"}}
{"jsonrpc":"2.0","method":"Events.actionFinished","params":{"actionId":"a7","sessionId":"s1","seq":42,"loadEpoch":2,"update":208,"status":"succeeded"}}
```

### Python client and scenarios

Use a Python 3.13 async client with a Playwright-style `Session`, `Menu` and `Locator`. Expose domain
methods and raw calls. A locator resolves again on each action within its menu generation. The client waits for visible,
enabled, stable bounds and a ready movie before clicking. Assertions retry observations to a
deadline and name the last state seen. Commands that change game state are issued once.

```python
# Proposed API. The fixture config supplies aliases and expected values.
async with await Skyrim.connect(endpoint, token=token) as game:
    await game.load_fixture("training-room")
    inventory = await game.ui.open_menu("InventoryMenu")
    await inventory.item("test-weapon").click()
    await expect(game.player.equipment("right")).to_equal("test-weapon")
    await inventory.close()
    result = await game.console.execute_fixture_query("player-health")
    await expect(result).to_equal(fixture.expected_health)
    await game.player.walk(meters=10, tolerance_m=0.5)
    await game.player.look_at(game.world.target("test-lever"))
    await game.world.activate(game.world.target("test-lever"))
    await expect(game.world.target("test-lever")).to_have_state("activated")
    await game.player.look_at(game.world.target("test-npc"))
    await game.world.activate(game.world.target("test-npc"))
    await expect(game.ui.menu("DialogueMenu")).to_be_open()
    await game.ui.menu("DialogueMenu").close()
    await game.player.look_at(game.world.target("test-opponent"))
    async with game.events.expect("Combat.hit", source="player", target="test-opponent"):
        await game.combat.attack(game.world.target("test-opponent"))
    capture = await game.capture.screenshot()
    assert capture.frame_id is not None and capture.artifact_id
```

The fixture supplies a clear measured walking segment, a lever, a dialogue NPC and a stationary
practice opponent with observable hit events. Record the unit conversion measured for the fixture.
The walking assertion checks actual displacement in the expected direction within 0.5 m, and reports
a blocked path as a failure. The smoke test also checks that the reported artifact decodes on the PC.

Record one local JSONL transcript with protocol, plugin and game identities, fixture digest, settings,
action arguments, event sequence and update/frame counters, assertion results and capture IDs.
Start by recording client actions. Add an opt-in recorder for supported in-game inputs with their
logical update offsets if a manual repro is needed. Replay from a fresh fixture and resolve logical
selectors again. Drive each action at its recorded prerequisite or verified update boundary.
Report the first divergent assertion, missing event or cursor gap with the last observed state.
Use semantic assertions with explicit tolerances. Keep local wall time as a watchdog and diagnostic.

Start with event waits and snapshots, including a post-load ready predicate and first playable
update. A presented frame, a simulation update, a Scaleform advance and calendar time are distinct.
For stepping, first prove a game-thread barrier can hold simulation while UI, rendering and the
watchdog continue, then count completed simulation updates over a repeated pause/step/resume trial.
Test each clock or RNG source that a fixture actually depends on. Use a stable save, load order,
INI values, camera, resolution and a quiet test cell. Record any RNG controls by scope. Leave global
RNG and exact frame replay out of the baseline while streaming, physics, AI and scripts can vary.

## Implementation route

- **Host and command server.** Use the official SKSE64 2.3.1 Steam build for 1.7.104 and a local
  x64 DLL. The Mac requests a fixed owner-local launcher over SSH. It runs SKSE as the normal test
  user in the logged-in interactive desktop, for example through an on-demand task configured for
  an interactive token. Preflight detects a missing desktop or an existing session. Use SKSE
  messaging/task callbacks where their timing fits. Network workers validate and queue requests,
  the game/UI thread owns game objects and the render thread owns immediate-context calls.
  Each thread returns owned results through bounded queues. A watchdog aborts a stalled run and
  the launcher can stop its test process. Stage the fixture copy before launch. Start with the
  verified retail load path, through the save/load manager if supported. Require a completed
  load, a playable update and no loading menu before making gameplay commands available.
  [Official SKSE downloads](https://skse.silverlock.org/) ·
  [Windows task logon types](https://learn.microsoft.com/en-us/windows/win32/taskschd/principal-logontype)
- **Menu and input.** Start from CommonLibSSE-NG declarations for `UI`, `UIMessageQueue`,
  `IMenu`, `MenuControls`, `ControlMap`, `BSInputDeviceManager` and `BSInputEventQueue`. Verify the
  normal open/close path for each menu, using the message queue where the retail path permits.
  Observe the open/close event and then movie readiness. Walk a bounded, menu-specific
  `IMenu::uiMovie` tree through `GFxMovieView` and `GFxValue` accessors. Build stable locators from
  exposed ActionScript paths or fixture item IDs, resolve visible hit bounds and translate
  stage coordinates to the active viewport. Drive pointer move/down/up through the verified
  movie or input handler and observe selection/equip. Insert synthesized events at the verified
  dispatch phase and use the game’s mapping, lifetime and consumption rules. [UI declarations](https://github.com/alandtse/CommonLibSSE-NG/tree/7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a/include/RE/U) ·
  [Movie declarations](https://github.com/alandtse/CommonLibSSE-NG/blob/7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a/include/RE/G/GFxMovieView.h)
- **Console, movement and combat.** Validate the `Console::ExecuteCommand` entry and the
  underlying command parser/script dispatch. Treat the CommonLib void return as dispatch and
  verify effects or collect a bounded, command-correlated console result. Use saved/restored
  selection where a supported command needs a target. Query `PlayerCharacter` and loaded
  `TESObjectREFR` handles on the owning thread. Use controls for look, walk, activate, attack
  and block. Validate that focus still names the requested reference at dispatch. Derive hit
  evidence from the verified hit event and correlate source, target and health where appropriate.
  [Console declarations](https://github.com/alandtse/CommonLibSSE-NG/blob/7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a/include/RE/C/Console.h) ·
  [Player declarations](https://github.com/alandtse/CommonLibSSE-NG/blob/7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a/include/RE/P/PlayerCharacter.h)
- **Screenshot.** Verify the active game swap chain and the render-thread site after UI composition
  and before Present. Get the D3D11 backbuffer, resolve or convert when format or sample count
  requires it, and copy to a staging texture. Poll readiness at later render boundaries with a
  deadline, map using row pitch and encode the copied pixels on a worker. Handle resize, device loss
  and backlog. Capture the game’s frame and return metadata plus an opaque ID. The Mac can
  retrieve an explicitly selected artifact into its owner-local `.local/` over the same SSH link.
  Use a verified callback if available. If the site needs a detour, use one pinned library, initially MinHook. [DXGI GetBuffer](https://learn.microsoft.com/en-us/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-getbuffer) ·
  [D3D11 CopyResource](https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nf-d3d11-id3d11devicecontext-copyresource) ·
  [D3D11 Map](https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nf-d3d11-id3d11devicecontext-map)

### Verify a binding on 1.7.104

1. **Pin and resolve.** Hash the stock image locally against the target pin. Record SKSE, plugin
   and header revisions, then enumerate every touched function, global, vtable slot, field, event,
   inline offset and transitive engine relocation used by the adapter. Resolve any community
   relocation ID in the exact local 1.7.104 table or establish the RVA directly from the owned
   binary. Compare with independent local static evidence. At runtime check the loaded module base,
   expected section and site fingerprint before use.
2. **Check how retail uses it.** Inspect local callers and callees, constructor and field accesses,
   and vtables or RTTI where available. Confirm the x64 ABI, argument and return shapes, `this`
   adjustments, field widths, alignment and base offsets, ownership and thread. Cross-check relevant
   project declarations and the pin-specific CrashLogger layout evidence. An assertion in a
   community header is a hypothesis about the target.
3. **Observe, then call.** On the owner’s stock session, exercise the retail action with a narrow
   debugger or observation probe. Confirm the expected class/subobject, access or event on two
   repeats, then run the adapter on the same path. Check a negative case such as a closed menu,
   expired handle or unavailable device. Record evidence, confidence and scope in the private
   ledger. Leave the capability disabled if a required site or field is unresolved. Cover startup,
   reload and teardown for any retained registration or callback state.
4. **Replace one binding at a time.** Use a project-owned declaration where its used ABI and layout
   have passed the same checks. Keep the release adapter calling the verified retail entry.
   Exercise a matched implementation through the placement path in F. Verify class layout
   properties individually for each adapter that uses them.

### Licences and local dependencies

- **SKSE64.** The upstream release notes ask modders to link to the official download and prohibit
  rehosting or bundling absent an exception. They direct extension authors to plugins, disallow
  modified SKSE releases and require source availability if a plugin includes SKSE source. Use the
  official installed build, with SDK files and binaries in owner-local dependency/install paths.
  Review the exact shipped files and any transitive SKSE portions before sharing a plugin. The
  project publishes its own adapter source and dependency instructions. [Pinned SKSE README](https://github.com/ianpatt/skse64/blob/25b72352adb6543fa6d0bd3795780672b2e238e0/skse64_readme.txt) ·
  [Pinned SKSE license notes](https://github.com/ianpatt/skse64/blob/25b72352adb6543fa6d0bd3795780672b2e238e0/skse64_license.txt)
- **CommonLibSSE-NG.** The revision at `c4ab853d095e81e3390b282d7ba01ab2f24ebf25` is MIT with
  copyright and permission notice retention. It predates this target and is only a declaration
  reference until validated. For the initial owner-local adapter, use the newer
  `v16.12.0` at `7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a` as the build candidate, with the same
  per-binding verification. Its GPL-3.0-or-later modding exception covers interoperation with the
  named modded code, including Skyrim. Upstream says a statically linked plugin must be under
  GPL-3.0-or-later or GPL-compatible terms. Its separate linking exception has corresponding-source
  terms for covered combinations, including the portions of modding libraries used. Keep the
  linked prototype and dependency tree local. Before any distribution, resolve the combined
  obligations with the exact pins, including SKSE, or use independently verified project-owned
  bindings. Keep shared protocol and Python client source independent of the native dependency.
  [MIT pin](https://github.com/CharmedBaryon/CommonLibSSE-NG/blob/c4ab853d095e81e3390b282d7ba01ab2f24ebf25/LICENSE) ·
  [GPL pin](https://github.com/alandtse/CommonLibSSE-NG/blob/7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a/README.md#license) ·
  [Exceptions](https://github.com/alandtse/CommonLibSSE-NG/blob/7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a/EXCEPTIONS.md)
- **Hook libraries.** MinHook v1.3.4 is two-clause BSD with notices, including its bundled
  disassembler. Detours v4.0.1 is MIT with notice retention. Either is a local build dependency
  if selected. Keep dependencies pinned and keep the originals and required notices with any
  permitted distribution. [MinHook](https://github.com/TsudaKageyu/minhook/blob/v1.3.4/LICENSE.txt) ·
  [Detours](https://github.com/microsoft/Detours/blob/v4.0.1/LICENSE.md)

## Workstreams

All six have the same sole owner. Start A and the menu probe in B, while a second agent, when
available, writes E’s client against a synthetic server or triages F’s static candidates. Finish B’s
input and console paths before C’s live controls. D can proceed after A and use the next Windows
slot. E runs the full scenario after B, C and D. F’s matching work can proceed in parallel and its
binding swap uses the completed regression scenario. Use one Windows runtime session at a time.

| Slot | Workstream | Depends on | Agent wall-clock estimate |
|---|---|---|---|
| A | Session and protocol host | PC link, interactive test desktop and pinned stock install | 1–2 days |
| B | Menus, input and console | A lifecycle and game/UI dispatch | 2–4 days |
| C | Movement, world interaction and combat | A session and B input dispatch | 2–4 days |
| D | Screenshots and rendering handoff | A session and verified render site | 1–2 days |
| E | Python client, scenarios and replay | A schema for mock work, B–D for full smoke | 2–3 days |
| F | Matching and project-owned bindings | Static inventory now, live substitution after A/B and E where applicable | 2–4 days for the first binding set |

These are planning estimates, about 10–19 agent-days of work with functioning Windows tooling and
a usable fixture. The elapsed schedule depends on agent capacity and shared PC access. F’s estimate
covers the first binding set. Matching whole classes and implementing the later `Render` domain
have separate scope.

### A. Session and protocol host

Workstream issue [#1225](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1225).

**Owner: Maintainer** · open to contributors (comment to join).

- **Deliverable.** Versioned schema and capability handshake, Mac-to-PC launcher and WebSocket
  connection, SKSE host lifecycle, bounded dispatch queue, fixture loader, event sequencing and
  failure recovery.
- **Acceptance.** From the Mac, start the stock session, verify the reported build, load a fixture
  and assert readiness, then close it. Repeat unattended. Refuse a bad token and wrong build and
  recover from a dropped connection without leaving a test process or held input behind.

### B. Menus, input and console

Workstream issue [#1226](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1226).

**Owner: Maintainer** · open to contributors (comment to join).

- **Deliverable.** Menu notifications and locators, inventory click/equip, reusable input dispatch
  and verified console command execution.
- **Acceptance.** Open inventory, click one known item and assert the equipment change after
  dispatch. Close inventory, reopen it and check that the old locator is stale. Run a verified
  read-only console query and assert its expected value or observed result on the fixture.

### C. Movement, world interaction and combat

Workstream issue [#1227](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1227).

**Owner: Maintainer** · open to contributors (comment to join).

- **Deliverable.** Player snapshots, movement and look, scoped queries and activation, attack/block
  and hit observations.
- **Acceptance.** Walk 10 m on a measured clear path within 0.5 m, activate a fixture object, start
  dialogue with a fixture NPC, then land a melee hit on the practice opponent. Assert position,
  the object change, dialogue open and matching hit source and target. Exercise a stale or wrong
  target as the negative case.

### D. Screenshots and rendering handoff

Workstream issue [#1228](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1228).

**Owner: Maintainer** · open to contributors (comment to join).

- **Deliverable.** Local backbuffer PNGs tied to frame IDs, plus a documented handoff from
  `Capture` to the future `Render` domain.
- **Acceptance.** Capture a recent frame with inventory visible, confirm that the PNG decodes
  at the reported size and the local frame shows the menu, then repeat after a viewport resize.
  Require a bounded timeout if a usable frame is unavailable. The later rendering acceptance is
  a local capture of one frame with its pass sequence and associated light set on the same frame ID.

### E. Python client, scenarios and replay

Workstream issue [#1229](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1229).

**Owner: Maintainer** · open to contributors (comment to join).

- **Deliverable.** Python 3.13 client and assertion runner, record/replay transcript, stock and
  exelink smoke launch profiles and a scenario usable by the runtime-pilot operator.
- **Acceptance.** From the Mac, run the inventory, console, 10 m walk, object and NPC activation,
  hit and screenshot scenario twice from fresh copies without human input. Record once and replay
  once on stock, then replay on a byte-identical exelink output with a recorded local relink report.
  An altered expectation reports its first divergence. Game artifacts remain local.

### F. Matching and project-owned bindings

Workstream issue [#1230](https://github.com/Mudcrab-Team/skyrim_decomp/issues/1230).

**Owner: Maintainer** · open to contributors (comment to join).

- **Deliverable.** Verify candidate ownership and prioritize exact adapter-path callees from the
  progress inventory. Land the first reviewed project-owned declarations and matched functions
  through the contributor path. Start with `UI`/`UIMessageQueue` or `ControlMap`/input declarations
  and a small reachable adapter-path function. Later replace the player/reference, movement and hit
  surfaces, then any capture-related accessor assigned with Rendering 1:1.
- **Acceptance.** One adapter binding builds against a verified project declaration and passes the
  same stock regression with and without the substitution. Its chosen function reaches `matched`
  through the existing gate. Show it was placed on the private exelink report and passes the same
  smoke if E’s relink scenario is available. Keep the comparison and runtime records independently
  identifiable.

## Avoiding collisions

1. The maintainer owns the milestone and each workstream. Contributors comment on the issue to join.
   Each task gets one agent at a time. The maintainer schedules independent work by available agent
   capacity and reserves the Windows slot when a task moves from mock or static work to live testing.
2. A owns lifecycle, the wire schema and dispatch scheduling. B, C and D own their game adapters.
   E owns the client and smoke scenarios. F owns reconstruction submissions and the provenance of
   replacement declarations. Reuse shared input, event and capture interfaces at those boundaries.
3. Check current assignment before starting a reconstruction and keep renderer matching under
   [Rendering 1:1](rendering.md). Count any shared binding dependency once. Follow the ordinary
   contributor route and per-PR scope limits.

## Progress

Build `sse-steam-1-7-104`. This handoff’s inventory was computed with Python 3.13 on tracked
public metadata at `65d20afe7fe768252fe6d1f06c5298bad1ca44cc`. Progress at
`2026-11-25T15:02:46Z` lists **41,979 matched** and **976 mapped**, 42,955 entries. Scope is
unknown. The queue was generated against progress at `2026-11-25T10:41:56Z` and lists all 18,868
entries for that snapshot across five verified shards. Of these, 278 are already matched in the
newer progress. Exclude them. The remainder is a list of published candidates, with potential
newly unlocked work missing. [Progress snapshot](https://github.com/Mudcrab-Team/skyrim_decomp/blob/65d20afe7fe768252fe6d1f06c5298bad1ca44cc/data/progress.json) ·
[Queue manifest](https://github.com/Mudcrab-Team/skyrim_decomp/blob/65d20afe7fe768252fe6d1f06c5298bad1ca44cc/data/ready-queue.json)

| Dependency group | Named | Matched | Mapped | Ready | Of ready, mapped |
|---|---:|---:|---:|---:|---:|
| A Save/load and time | 50 | 20 | 0 | 4 | 0 |
| B Native menus | 131 | 17 | 2 | 13 | 1 |
| B Scaleform movie | 169 | 5 | 0 | 5 | 0 |
| B Input and control mapping | 143 | 41 | 18 | 33 | 8 |
| B Console and script command | 77 | 13 | 0 | 6 | 0 |
| C Player and world | 511 | 232 | 43 | 28 | 7 |
| C Movement | 108 | 43 | 35 | 21 | 10 |
| C Combat | 826 | 470 | 32 | 63 | 10 |
| D Screenshot dependencies | 55 | 10 | 1 | 12 | 0 |
| **Total** | **2,070** | **851** | **131** | **185** | **36** |

Read `data/progress.json`, the queue manifest and every `entries` shard. Verify each shard hash
and count. Join by build ID and numeric RVA. For each RVA in progress or the generated CrashLogger
name table, remove a leading `thunk_`, and take the owner before the final `::`. Keep exact
owners from the lists below. Prefer the CrashLogger owner if both names assign different groups
(three rows). Count each RVA once. `Mapped` is the progress status. `Ready` intersects the
published queue with the named set after excluding current matches. Of those 185, 149 have no
progress entry. Class names can include methods unrelated to the adapter, and some adapter
entry points remain unnamed. This is a shortlist by class, with no live claim or give-up check.
The data support these counts at the stated revisions. Runtime reachability and binding
availability remain open. [CrashLogger names, CRASHLOGGER_PDB(59818@2026.10.24)](https://github.com/Mudcrab-Team/skyrim_decomp/tree/65d20afe7fe768252fe6d1f06c5298bad1ca44cc/reconstruction/generated/crashlogger_pdb/names)

<details><summary>Class inventory</summary>

- **A Save/load and time.** `BGSSaveLoadManager`, `BGSSaveLoadGame`, `UISaveLoadManager`,
  `TimeManager`.
- **B Native menus.** `UI`, `UIManager`, `MenuManager`, `UIMessageQueue`, `IMenu`,
  `InventoryMenu`, `InventoryChanges`, `InventoryEntryData`, `ContainerMenu`, `DialogueMenu`,
  `MainMenu`, `HUDMenu`, `CursorMenu`, `MenuTopicManager`.
- **B Scaleform movie.** `GFxMovie`, `GFxMovieView`, `GFxMovieRoot`, `GFxValue`,
  `GFxValue::ObjectInterface`, `GFxSprite`, `GFxDisplayList`, `GFxMouseState`.
- **B Input and control mapping.** `BSInputDeviceManager`, `BSInputEventQueue`, `BSInputDevice`,
  `BSIInputDevice`, `BSDirectInputManager`, `BSWin32KeyboardDevice`, `BSWin32MouseDevice`,
  `BSWin32GamepadDevice`, `InputEvent`, `ButtonEvent`, `MouseMoveEvent`, `ThumbstickEvent`,
  `ControlMap`, `MenuControls`, `MenuEventHandler`, `PlayerControls`, `PlayerInputHandler`.
- **B Console and script command.** `Console`, `ConsoleLog`, `ConsoleCommand`,
  `ConsoleNativeUIMenu`, `ConsoleOpenHandler`, `Script`, `ScriptCompiler`.
- **C Player and world.** `PlayerCharacter`, `TESObjectREFR`, `CrosshairPickData`,
  `ActivateHandler`, `ActorEquipManager`.
- **C Movement.** `MovementController`, `MovementControllerAI`, `MovementControllerNPC`,
  `MovementHandlerAgentPlayerControls`, `MovementHandlerAgentPlayerControlsActionTrigger`,
  `MovementPlannerAgentDirectControl`, `bhkCharacterController`.
- **C Combat.** `AttackBlockHandler`, `Actor`, `ActorState`, `ActorProcess`, `AIProcess`,
  `HitData`, `TESHitEvent`, `HitFrameHandler`, `CombatController`, `CombatBehaviorController`,
  `CombatAimController`, `CombatMeleeAimController`.
- **D Screenshot dependencies.** `BSGraphics::Renderer`, `Renderer`, `RendererShadowState`.
  Treat `Renderer` as a named dependency for counting. Prove its relationship to the bound
  renderer before using it. Pass and light matching stays with Rendering 1:1.

</details>

Start by checking whether the ready candidates `UI::OnEnterExitItemMenu` (20 bytes),
`ControlMap::SetControlsState` (14 bytes), `ControlMap::GetControlsState` (18 bytes) and
`GFxSprite::OnEvent` (96 bytes) are exercised by the fixture. Those names are
`CRASHLOGGER_PDB(59818@2026.10.24)` labels. The published queue supports callee readiness at its
own timestamp. The binding ledger must establish signature, thread and reachability before a
candidate drives runtime design. Zero named rows for `GFxValue`, `CrosshairPickData`,
`MovementController` and `TESHitEvent` in this selection leave open data-type and naming work.

## First slice

A bounded pass through A, B and E, estimated at 1–2 agent-days with a working PC link and fixture.
Start SKSE from the Mac, verify the handshake, load a disposable save and observe one playable
update. Open inventory through the verified retail path, assert that its movie is ready, close it,
assert closure and stop the run. Repeat from a fresh copy without human input. Keep one
sanitized pass/fail result and the full transcript locally. Add the locator click, walking,
combat and capture after this path holds.

## Risks

- **Stability.** The biggest risk is a plausible community layout, callback phase or thread
  assumption that fails during a load or menu transition. Verify only the fields and entry points
  the feature uses, invalidate stale handles, bound each queue and deadline, and test teardown
  and a fail-closed launch. Clear held inputs on loss of session. A crashed or hung run invalidates
  its affected observations.
- **Updates.** Pin the game hash, SKSE, dependency revisions and capabilities. The launcher and
  plugin refuse a different build before binding anything. An updated game requires a new scope
  decision and repeated binding checks.
- **Repeatability.** AI, physics, scripts and streaming can change the next observable state even on
  the same build. Keep a narrow fixture, report timing and the first divergence, and use
  state-based assertions as the acceptance baseline.
- **Privacy and licences.** Keep the offline test profile isolated from personal saves, with
  autosaves and cloud sync disabled for the profile. Keep all game captures, raw evidence and
  locally linked binaries private. Publish sanitized findings and original artifacts after source
  review. Resolve any SKSE/CommonLib licence uncertainty before publishing affected material.
