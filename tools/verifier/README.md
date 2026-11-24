# Verifier worker recipe and scripts

Reproduces the compiler worker described in `findings/boat-pilot.md`: MSVC v141
(Visual Studio 2017 15.9 Build Tools, x64 host and target) under Wine on a fresh x86-64
Ubuntu 24.04 machine. The pilot scripts build and compare original synthetic code only.
`verify_function.py`, `tu_task.py` and `match_record.py` are the per-function path: they compare
a compiled reconstruction against the pinned image you supply (private, under the gates in
`AGENTS.md`) and assemble the sanitized match record. No script here contains game data.

The recipe establishes a build worker. It does not establish that this is the compiler the
target was built with.

## Per-function commands

Use the independently configured local/SSH runners. Boat is retired.

```sh
tools/verifier/attempt .local/tasks/<task-id>          # compile and compare one unit
tools/verifier/attempt --clean .local/tasks/<task-id>  # clean this task's runner scratch
tools/verifier/confirm .local/tasks/<task-id>          # reproduce on configured independent hosts
tools/verifier/confirm --session <task-dir>... [--out DIR] # confirm a batch
```

## Runners: where attempts and confirms run

`.local/verifier/runners.json` (private; example `runners.example.json`, parser `runners.py`)
names the hosts. Supported operation uses `local` (a local
compiler installation, no network) and `ssh` (a host reached with its own private ssh_config).
`"attempt"` picks the host `attempt` uses; `"confirm"` lists the compile hosts of a runner confirm
(two machines, two loaders). Configure these explicitly; the historical Boat fallback is retired.

A local or ssh run uploads one archive (the unit's include closure, the comparator and host
scripts, the spec) and `host_agent.py`; the command line holds only paths and fixed options. The
host compiles and compares with `unit_build.py` (`--loader wine|native`), packs its work directory
for one fetch and deletes the run. `result.json` carries the host's OS, loader and the hashes of
the compiler binaries it ran, and the seconds each phase took. Each host has `max_parallel` slots (file locks under
`.local/verifier/runner-slots/`); attempts beyond that wait in turn.

A machine that only orchestrates sets a top-level `"local_max_heavy": N` in the same file (default: no
cap, so contributors and CI are unaffected). Every heavy local job of every checkout sharing that
`.local/verifier` then holds one of N machine-wide slots (file locks under `.local/verifier/local-heavy/`,
no daemon, released when the process dies): a compile on a local host, `attempt`'s binding and
diagnostics, the permuter's local scoring pool, the generators' probe compiles and the `check.py` fan-out
(which gets no more workers than the slots it was granted). A job that has to wait prints one
`local load guard: ... waits for a free slot` line. `attempt` also prefers a reachable ssh host over a
local one while the cap is set. `SR_LOCAL_MAX_HEAVY` overrides the file for one process tree (a number,
or `0` to lift the cap); `python3 tools/local_load.py` shows the cap and the slots held.

```sh
python3 tools/verifier/runners.py status                    # each host: toolchain, image, CPUs, busy slots
python3 tools/verifier/reproduce_records.py --host <name>   # recompile every recorded unit there; equal/different
```

A runner confirm writes records under the "Runner hosts" condition of `docs/verification.md`:
into `reports/` only with a `local` host among the confirm hosts (it cross-compares the other
hosts' objects), after every host hashed its toolchain during that run and reported the loader
its config names, Windows for a native compile, and two operating systems between them. `--out`
writes inspection records under the same checks except the `local` host requirement. `reproduce_records.py` keeps each
run's summary under `summaries/` of its output directory. Boat provisioning is retired.

Speed and restarts of a runner confirm. Each host takes the units in list order: the local host
one unit per slot, an ssh host in batches of `batch` units (default twice `max_parallel`) with
one upload, one `host_agent.py batch` command running up to `max_parallel` units at once, one
fetch and one clean per batch, two batches in flight so one transfers while the other compiles.
Archives are xz-compressed. Every unit is still a fresh copy checked against its own spec, with
its own toolchain and image hash measured in that run (`fresh_prep`; the check costs well under
a second). As soon as all hosts have a unit, it is cross-compared, its records are written and
its lines go to the console and to `.local/verifier/confirm-logs/<UTC>-<id>.log`. Each scheduled
unit gets a tombstone in `.local/verifier/confirm-journal/` and each successful unit gets a new
entry (one journal per output: `reports` or the `--out` directory). `confirm --resume` (with
`--replace` for units it must redo) first probes every host's toolchain afresh, then skips a unit
only when its journal entry has the same input key (every shipped file, the record tools and
validator, the base commit and uncommitted inputs, the comparator source hash, the Mac comparison
image, the hosts and the output), the same compiler hashes on every host as just measured, and
records still unchanged on disk; anything else runs again. A new commit changes the key, so units
run again after a commit. A run into `reports/` needs no prior `--out` pass: records are validated
before they are written, `check.py` runs at the end, and `git diff` shows every change before it
is committed.

`<task-id>/task.json` (private) names the build id, translation unit, recipe, symbol map
and functions. The format is in `pipeline.py`. Sources come from the current checkout.
Runner attempts bind symbols using the compiled object, retain private diagnostics, and count
attempts under the profile budget. Infrastructure refusals are not comparator evidence.

Confirmation binds source/include digests, recipe and map hashes, and the comparator revision.
It checks independently installed toolchains and target copies on configured hosts, cross-compares
objects, validates records before publication, and refuses to overwrite records without
`--replace`. Private image, toolchain, scratch and diagnostic paths belong in ignored config.

## Files

- `runners.py`, `host_agent.py`, `confirm_runners.py`, `reproduce_records.py`, `runners.example.json`:
  runner selection and the local/ssh backends, the host-side script shipped with every run,
  confirm on runner hosts, and the reproduction of committed records on one host (tests in
  `tests/test_runners.py` use a stub ssh transport and a fake compiler).
- `session`, `vsession.py`, `confirm_session.py`, `starts.py`: verifier sessions, session-mode
  confirm and the starts budget (tests in `tests/test_session.py` use a fake `boat` CLI).
- `attempt`, `confirm`: the commands above; `pipeline.py` holds their shared logic, `boatctl.py`
  the Boat CLI calls, `disasm.py` the local side-by-side disassembly, `bind.py` the binding of
  decorated names to target RVAs (rules and hint format in its docstring).
- `align.py`: aligned diagnostics for a failing function. It normalises both listings (registers
  as widths, references as RVAs, branches as labels), aligns them, names each difference in a
  fixed vocabulary that maps onto `docs/matching-cookbook.md`, and gives one distance with
  prologue, body and reference components (formula in its docstring; 0 only for identical bytes).
  `attempt` prints its summary (no bytes, no instruction text) under each failing function and
  writes `align.txt` (private aligned listing) and `align.json` (for a search tool) next to the
  side-by-side. Run it on stored attempts with `tools/verifier/align.py --attempt <dir>`. A
  reading aid and a score, never evidence of a match.
- `permute.py`: source permuter for one near-miss function, no model in the loop
  ([docs/permuter.md](../../docs/permuter.md)). Seeded rewrites of one body from the cookbook's
  mechanisable rules, every candidate linted, batches compiled in parallel on the standing
  machine in one `boat exec` each and scored with `align.py`; a distance-0 winner is compiled
  and compared once more by `unit_build.py`.
- `unit_build.py`: runs on the verifier host. Checks the synced copy against the spec's hashes,
  the toolchain against `pinned.sha256` and the image against `builds/target.json` (once per
  boot), compiles with the build-path checks of `docs/verification.md` (cleared `INCLUDE`/`CL`/
  `_CL_`, `/showIncludes` equal to the include closure), then runs `verify_function.py` per
  function.
- `setup_toolchain.sh`: installs Wine and msitools from the Ubuntu archive, checks out
  msvc-wine at a pinned commit, downloads a pinned Visual Studio installer manifest (checked by
  SHA-256), downloads and unpacks the toolset and Windows SDK from Microsoft's servers, then
  checks the compiler binaries against `pinned.sha256`. Running it accepts the Microsoft Build
  Tools licence (`--accept-license`); only run it where that licence basis is recorded.
- `pinned.sha256`: expected SHA-256 of `cl.exe`, `c1xx.dll`, `c2.dll` and `link.exe`.
- `build_pilot.sh <msvc-dir> <new-output-dir>`: compiles `synthetic/pilot.cpp` and
  `synthetic/pilot_variant.cpp` and links `pilot.dll` with a map file. Run it twice.
- `pilot_compare.py determinism A B`: attributes every differing byte between two builds to a
  named field; prints hashes and counts only.
- `pilot_compare.py compare A B --work .local/... --recipe recipe.json`: runs
  `tools/compare.py` on object A against image B for each pilot function, plus negative cases.
  The work directory must be under `.local/` because the comparator writes diagnostics there.
- `build_eh.sh <msvc-dir> <new-output-dir>`: compiles `synthetic/eh_cases.cpp` with the first
  recipe's flags and `synthetic/eh_gs.cpp` with `/GS` added, and links `eh.dll` with a map.
- `eh_compare.py <build-dir>`: comparator contract v2 on that build: every exported function
  compared object against DLL (try/catch, destructors, SEH, GS handlers, jump tables, chained
  unwind), then negative cases on altered copies of the image or map. Metadata output only.
- `eh_census.py <image> [--sample verdicts.tsv]`: walks every function's unwind chain and handler
  data in an image with the comparator's layouts and prints counts only: handlers by kind, how
  many decode completely, reasons for the rest, and with `--sample` the survey sample's supported
  share before and after contract v2.
- `build_tls.sh <msvc-dir> <new-output-dir>`: compiles `synthetic/tls_cases.cpp` (linked into
  `tls.dll` with a map) and the perturbed `synthetic/tls_variant.cpp` (compiled only).
- `tls_compare.py <build-dir>`: the comparator's thread-local rules on that build: every `tls_`
  function passes with a map whose TLS-template names are `thread-local` entries; the variant
  object and altered maps or images fail. Metadata output only.
- `synthetic/`: original test sources. No third-party code.
- `verify_function.py`: runs `tools/compare.py` for one candidate function from a task
  description file and prints a sanitized summary.
- `tu_task.py`: writes that task description and the build record for a compiled
  translation unit under `reconstruction/`. It takes identity from the inventory and
  `builds/target.json`, and the source revision from `tools/source_digest.py`.
- `match_record.py`: assembles a match record under `reports/` from comparator reports and refuses
  any record `tools/check.py` would reject (`reports/README.md`).

After comparison, `attempt` prints nonblocking label warnings from `tools/check_labels.py`.
They never change comparison exit status and are not match evidence.

Related tools outside this directory:

- `tools/compare.py` (with `tools/pecoff.py`): the comparator, contract in
  `docs/comparator-contract.md`. Changing either file makes every match record stale.
- `tools/source_digest.py` (`tu-sha256-v1`, raw bytes) and `tools/digest_v2.py` (`tu-sha256-v2`, prose comments ignored; the default for new records): the digest of a translation unit, used as the source
  revision by tasks, records and Reviewer records.
- `tools/check.py`: the validator, including the match gate (`docs/verification.md`).
- `tools/accept_function.py`: records a Reviewer `approve` and sets one inventory entry to
  `matched`, or revokes an acceptance (`--revoke`). It refuses anything the gate would reject.

## Steps

From a checkout (or a copy of `tools/compare.py`, `tools/pecoff.py` and `tools/verifier/`) on
the worker machine. Copy no credentials and no game-derived files to it.

```sh
tools/verifier/setup_toolchain.sh "$HOME/msvc"
tools/verifier/build_pilot.sh "$HOME/msvc" .local/pilot/a
tools/verifier/build_pilot.sh "$HOME/msvc" .local/pilot/b
python3 -I tools/verifier/pilot_compare.py determinism .local/pilot/a .local/pilot/b
python3 -I tools/verifier/pilot_compare.py compare .local/pilot/a .local/pilot/b \
  --work .local/pilot/compare --recipe .local/pilot/recipe.json
```

`recipe.json` names the compiler hash and version and the flags from `build_pilot.sh`; its
format is the one `docs/comparator-contract.md` describes.

## Known limits of the recipe

- The installer manifest is pinned by URL. If Microsoft withdraws that URL, the recipe stops
  at the manifest hash check; it never silently follows the channel to a newer release.
- Package payloads are verified against the manifest by `vsdownload.py`; the toolset binaries
  are then checked against `pinned.sha256`. The SDK files are not individually pinned.
- Boat machines are shared-vCPU VMs; timing is not representative. Wine is the Ubuntu 24.04
  package, not a pinned upstream build; its version is printed by the setup script.
