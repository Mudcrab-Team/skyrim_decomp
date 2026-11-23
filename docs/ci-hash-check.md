# Advisory MSVC hash checks for contributor pull requests

Task p124, 2026-11-14. Engineer: gpt-6.1-sol; human owner: awarebayes. Exposure: public
reconstruction source and sanitized accepted records only; no private game input was used to
implement this prototype. Build identity is the pinned `sse-steam-1-7-104` manifest in
`builds/target.json`. This document is a tooling design, not a behavior or clean-room claim.

## Phase 1: prove the compiler with existing public records

Dispatch `.github/workflows/ci-hash-check.yml` on main. The `windows-2022` job asks the runner's
Visual Studio installer to add `Microsoft.VisualStudio.Component.VC.v141.x86.x64` and the pinned
SDK headers. `tools/ci_msvc_install.ps1` records installation wall time. `tools/ci_hash_check.py
probe` prints the compiler version, size and SHA-256, plus the hashes and sizes of `c1xx.dll`,
`c2.dll` and `link.exe`. `MATCH` requires x64 version 19.16.27054 and every hash in
`tools/verifier/pinned.sha256`; a v141 label alone proves nothing.

If the installed component differs or the self-test fails, the job tries Microsoft's evergreen
VS2017 Build Tools bootstrapper at `https://aka.ms/vs/15/release/vs_buildtools.exe`. It checks
the bootstrapper's Microsoft Authenticode signature and supplies the existing fixed 15.9.85
catalog URL and SHA-256 from `tools/verifier/setup_toolchain.sh` through
`--installCatalogUri`. It probes the resulting binaries against exactly the same pins. This
tests an official exact-version source without assuming that the evergreen installer or a
toolset directory name will yield the pin. Failure or mismatch remains visible; no pin changes.

The public self-test compiles three separate units twice, with the flags read from the accepted
record's recipe, the verifier's cleared environment and include-closure checks, and a 180-second
compile timeout. It compares these functions with their existing public records:

- `NiTimeController::ProcessClone`, RVA `0xef8900`, 53 bytes, the contributor setup self-test.
- `NiAVObject::GetCollisionObject` (const), RVA `0x405a50`, 33 bytes.
- `TESForm::GetGoldValue`, RVA `0x1f3560`, 157 bytes.

The expected values come from the accepted records, checked for source-digest, recipe and
cross-run agreement, rather than newly published target data. Extraction calls the unchanged
comparator's `find_function` and `check_relocation_layout`; hashing calls its
`code_section_sha256` directly. These three references have one code section and no funclet
sections. Phase 1 tests clean-compilation determinism on these units, not all C++ features.

**Existing hash semantics:** `code-section-sha256-v1` hashes section names, lengths, bytes and
relocation offset/type/target identity. It excludes object timestamps, symbol indices and debug
paths. It does not simply zero relocation fields. Phase 1 reproduces this existing public hash;
it does not pretend it is the future masked-target hash below. Neither comparison runs the
game comparator against a target image on CI.

Phase 1 used the official VS installer and no Actions cache. That historical decision is
superseded by the verified package/cache procedure below; the compatibility manual workflow
now calls the same package-only workflow as Phase 2. Compiler objects and raw diagnostics
still remain in scratch and are never cached or uploaded.

## Phase 2: published target hashes (p128)

p128 implements the maintainer-authorized publication after p124's successful compiler pilot.
There is **no size threshold**. Tiny functions' SHA-256 hashes are brute-forceable: the maintainer
accepted this, saying "you are being too strict" and allowing all sizes; the full verbatim
statement is in `docs/authorizations.md`. This is a publication decision, not a legality claim.

`tools/target_hashes.py` runs only locally against the owner's SHA-256-checked pinned image.
It processes every `(build id, RVA, size)` in the current `data/progress.json` inventory, including
unmatched functions, plus `contributor-targets.json`: the offered `contrib.py next` candidates and
all functions in the current open claim snapshot. Claim addresses outside progress are resolved
against local function/pdata boundaries; unresolved identities stop generation. The checked-in
offered inventory records public claim URLs/scopes and hashes of its input snapshots. This
coverage is smaller than the full executable census, and grows in address-range chunks. `target_hash_offers.py` also
offers unmapped ordinary functions that the local analysis supports (verdict `supported` or `caution`). No class or
layout is needed: a function the table gives no usable class for, or whose class has no layout, is offered with no class
on its row, and the contributor names the class with `--class` when starting it. A class with a real layout unit, or a
generated CrashLogger layout header (`reconstruction/generated/crashlogger_pdb/types/`, label
`CRASHLOGGER_PDB(59818@version)`) whose fullest PDB type is a struct or class with a size and a placeable unit
(`tools/unit_paths.py`), is still named on the row and ranks first; the PDB layout is a community reconstruction, not
evidence. The local-support verdict is unaffected: it comes from the analysis of the function itself and is required
either way. `contrib.py` accepts every offered row and `tools/record.py` creates its inventory entry on acceptance
(`findings/claim-time-mapping.md`). Offered rows stay offered until they are recorded: a row carries `class`, or
`window` when it has none, and the refill keeps both. A chunk is added when fewer than the low-water mark (2,000 by
default, `--low-water`, `SR_WINDOW_LOW_WATER` for the bot) are left to claim: the next slice (2,000 by default,
`--slice`, `SR_WINDOW_SLICE`) of qualifying functions by ascending address, so a chunk is a stretch of the image and
the next one starts where the last ended. `--range LOW-HIGH` publishes every qualifying function with
`LOW <= RVA < HIGH` at once, whatever is left to claim; a very large publication is shipped as several such ranges, each
checked before the next. Within a chunk the order is real-unit classes first, then PDB-layout classes, then the rest;
small and medium functions first, known names (community, RTTI, address library) and classes with matched siblings ahead
of the rest, very large and known-hard shapes last. Functions that internal workers have planned (private plan
files under `.local/twins` and `.local/stamp-sweep`, passed as `--reserved-dir`) are skipped and, if not claimed,
withdrawn from the window; the plans themselves are never published. The bot logs the slice and a line with
claimable left, claimed and the daily burn rate. An open PR may also claim a function outside the window: when its header claims an RVA that has no
row and the RVA is an ordinary, locally supported function start of the private table, the bot passes it to
`target_hash_offers.py --extra-rva`, which publishes the same hash-only row (no class filter; at most 256 per run, kept
until recorded), and the head gets a fresh hash run against the new base. Claims are read by `tools/rva_headers.py`: the compact
`// 0x<rva> <Name>` lines, `RVA 0x<rva>, <n> bytes` records and `compared at RVA ...` labels, never an address in prose.
A claim that still has no row is listed in the sticky comment. Install the
local extraction dependency `iced-x86==1.21.0` in an ignored environment. For example:

```sh
python3.13 tools/target_hash_offers.py --image <private-image> \
    --function-table .local/analysis/functions.jsonl
python3.13 tools/target_hashes.py --image <private-image> \
    --out data/target-hashes/sse-steam-1-7-104.json
```

The index manifest binds bounded JSON shards with SHA-256 and row counts, keeping every
file below the existing publication cap. It records the build, image hash, inventory snapshot hash, comparator and normalizer
source hashes, compiler-pin file hash and recipe hashes. Each row records RVA, size, extraction
method, `normalized_sha256` and `layout_sha256`; the build and normalization version are inherited
from the manifest. **No bytes, mask contents, reference destinations, listings or decompiler output
are published.** `layout_sha256` commits to the ordered field offsets, widths and relocation types;
only its digest is public. It prevents a candidate from erasing arbitrary instructions by adding
relocations. It does not reveal a mask or reconstruct any instruction bytes.

Normalization version `relocation-masked-sha256-v1` is ordinary, key-free **SHA-256 of the full
function buffer with each four-byte relocation field replaced by zeros**. Size remains an explicit
identity field. The candidate uses the unchanged comparator's `find_function` and
`check_relocation_layout`, including its supported types, widths, overlap and bounds checks.
Every unmasked byte, including internal branches and padding, stays exact. This hash is distinct
from the stronger `code-section-sha256-v1` in Phase 1: reference names, addends, unwind/EH data and
funclets are outside this advisory digest and remain the local comparator's job.

A linked PE does not retain the original COFF relocations. The local extractor infers RIP-relative
four-byte reference fields (including REL32 trailing-immediate variants), four-byte direct calls
(including self calls) and branches outside the function. Other internal branches stay unmasked. It never guesses address-like immediates.
This is labelled `linked-reference-inference`, **not a claim of recovered original relocations**.
ADDR32NB, SECREL, linker transformations and unusual instruction streams can require additional
local evidence. An optional private layout file can supply comparator-checked fields; it never
leaves `.local/`. Undecodable ranges receive an explicitly unmasked digest and
`unmasked-unsupported`; the CI checker always returns `no-target` for these. A different candidate
relocation layout also returns `no-target`, rather than passing under candidate-selected masking.
Hashes cover the recorded ranges; they do not independently validate inventory extents.

`data/target-hashes/determinism-sample.json` pins 50 accepted external, single-code-section
references, stratified across distinct accepted sizes. Local validation compiles each twice,
checks normalized object/target hash equality and layout agreement, and reproduces the unchanged
full comparator pass on each compile. Run `tools/target_hash_determinism.py --image <private-image> --msvc <private-msvc>
--work .local/<audit>` to reproduce locally with the recipe and the accepted record's comparator
engine (including runtime records). Raw inputs and masks stay in `.local/p128/`; measured
results and size range are in the p128 handoff. The push/dispatch Windows job separately compiles
these 50 public references twice against the same published target hashes. This exercises the
format across the accepted size range; it does not prove inferred masks for all unmatched code.
The manifest is regenerated deliberately on a maintainer machine when inventory extents,
normalization, comparator, pins or recipes change; CI never needs a game image.
The PR bot refreshes it in its post-merge regenerate commit after a mapping-only PR, using
`SR_TARGET_IMAGE` (and optionally `SR_FUNCTION_TABLE`) on its host, so main's hash test stays green.

## PR job and p123 integration

`.github/workflows/ci-target-hash.yml` runs on reconstruction pull requests. It uses a disposable
GitHub-hosted Windows runner, `contents: read`, no secrets, persisted checkout credentials, OIDC,
private inputs or object execution. The trusted checkout is the event's immutable **base SHA**.
Only its tools, recipes, inventory and target commitments run. The head SHA is fetched as git
objects; `prepare` reads bounded regular UTF-8 reconstruction blobs from the PR diff and overlays
them on a separate trusted source tree. It enforces the contributor path/deletion/file-size rules
and the same source lint; PR symlinks, recipes, response files and build commands are refused; CI tooling blobs are ignored,
never materialized or executed.
It never checks out PR tools or imports PR Python. Header edits trigger affected units too.

Known RVA/symbol/recipe bindings come from base records. A new unit can request a public target
in its source header with `// CI hash: 0x<RVA> <COFF-symbol>`. This is only a request to compare:
it cannot change a target's size, committed layout, digest or fixed default v141 recipe. Unknown
or unsupported bindings remain `no-target`. The compiler runs through `contrib.compile_unit`
with fixed recipe flags, cleared environment, include-closure checks, exact /showIncludes
agreement and its timeout. All four compiler pins and the pinned SDK headers must match.

Results contain only public identities/digests and `hash-match`, `mismatch` or `no-target` per
function, with `acceptance: not-evaluated`. Compile failures are sanitized as `mismatch` with
`compile-failed`; no compiler output, bytes or diffs enter logs or artifacts. Mismatches fail the
advisory job, while absent coverage remains visibly `no-target`. No-target is never hash equality.
The compiler's parser still receives untrusted C++, bounded by compile and job timeouts on a
runner without private data. Compiler packages, objects and diagnostics stay in scratch.

The p123 adapter `tools/contrib_hash_signal.py:advisory_hash_signal` consumes GitHub check-run API
metadata, selects only the latest GitHub Actions `target-hashes` job for the exact PR head SHA,
and returns an explicitly advisory signal (absent/pending/success/failure/etc.). The sanitized
JSON summary also records trusted base, head and tool/manifest/pin digests for investigation.
A PR can edit its own workflow; an apparently successful check cannot authenticate itself.
The adapter never changes the acceptance decision, authorizes compilation locally, or suppresses
intake or verification. `tools/contrib_autopilot.py` records this signal in the exact-head revision
state on every intake attempt. API errors produce `unavailable`. A successful job can still
contain `no-target` rows and is not a claim of hash coverage. Contributor intake, full comparison
on **two independent local hosts**, independent
Reviewer approval and integrated-source checks remain mandatory for `matched`. GitHub CI is
neither an acceptance host nor a substitute for any acceptance rule.

## Fast, fully verified toolchain setup and cache

The maintainer approved package-only extraction and a verified CI cache, superseding p124's
no-cache decision. awarebayes's statement, verbatim:

> legal.md is made up by me and can be rewritten, there is no particular reason it is what it is, i am open to it if 2 does not hold

The maintainer's condition 2, cache reliability, is met by full-manifest verification. Fork PRs
can restore this cache; that visibility is explicitly accepted. See `LEGAL.md` for this scoped
project-policy authorization. Game data, candidate objects and compiler diagnostics never enter it.

`tools/ci_toolchain.py` fetches the VSMAN at `recipe_pins.VSMAN_URL`, verifies
`VSMAN_SHA256`, and checks every selected URL/hash/size against that catalog before downloading.
The 40-payload plan contains only the x64 v141 compiler/CRT and the SDK headers and libraries the
recipe needs. Each payload's SHA-256 is checked before VSIX extraction or SDK MSI administrative
extraction into runner scratch. No Visual Studio installer or machine-wide registration runs.
The original selection/extraction approach is
[msvc-wine at the pinned revision](https://github.com/mstorsjo/msvc-wine/blob/d8a499efde3e1bd1862e2bebac976640c5f4c1fe/vsdownload.py);
this implementation is original infrastructure using Python ZIP extraction and native `msiexec /a`.

The tracked full-file manifest binds **every one of 4,199 files** in the curated toolset and SDK
tree, plus all four compiler pins. Its index SHA-256 is the exact Actions cache key, with no
prefix fallback. Shards remain below the existing publication size limit. The trusted manifest
comes from the base checkout, never from the cache. After every restore, the exact full file set,
each size/SHA-256, and all four pins are checked again. Missing, extra, changed or linked files
invalidate the restore. The restored tree is discarded and official payloads fetched fresh;
fresh extraction must pass the same complete manifest before any compilation or cache save.
Tests mutate SDK headers while preserving compiler pins, add/remove files, inject a cached
manifest and replace a root with a symlink; none is accepted.

The compiler is invoked by explicit `cl.exe` path with fixed `INCLUDE` and `LIB` roots under the
verified tree. There is no reliance on a developer command prompt or a globally installed SDK.
Run `ci-target-hash.yml` manually with `cold=true` to skip restoration and measure cold fetch,
then with `cold=false` to measure restoration plus full verification. `setup_seconds` starts
before the cache step and includes its restore time. The successful installer baseline was
**340.33 seconds**; observed cold/cache timings and run SHAs are in the p128 handoff, not assumed.

## Scheduling and the publication lane

The advisory job runs for contributor reconstruction/CI-input PRs, nightly on main, and by
`workflow_dispatch`. It does not run on lane pushes. PR tooling blobs are never executed: a
CI-input-only PR checks the trusted base's 50 references instead. C++ changes retain source intake.

The lane invokes `ci_status.py --without-advisory`. This omits only the two explicitly named
MSVC advisory workflows, requires Infrastructure and Pages to be present, and retains every
required or unknown workflow failure. The default CI-status command still reports advisory reds.
A pending or missing required workflow is not green. Hash checking itself is unchanged.

`flow.py tooling-push --repair-red <full-red-SHA> --wait-lane` is an isolated tooling repair
path, not a general CI override. It requires that exact SHA still be origin head, reproduces
completed RED CI, and admits only explicitly mapped advisory failures. Required/unknown reds,
unavailable/pending results, unrelated paths and function acceptance changes are refused. Every
failed workflow must have an actual input changed; supporting docs/tests alone do not qualify.
The red SHA, workflow/run identities, candidate SHA and changed paths are saved in the receipt.
All normal full checks and FF-only push remain required. Acceptance requests stay queued.

After a repair push the lane dispatches the repaired advisory workflow while retaining the push
lease, then waits for that workflow and required CI on the exact new SHA. A saved receipt resumes
this observation without another push; `--require-workflow` prevents an absent advisory run from
being reported green. Additional repairable workflows need an explicit input mapping; this path
cannot waive comparator, validator, Reviewer or two-host evidence.

## Sources and limits

Microsoft documents the [v141 component](https://learn.microsoft.com/en-us/visualstudio/install/workload-component-id-vs-build-tools?view=vs-2022)
and the [installer parameters](https://learn.microsoft.com/en-us/visualstudio/install/use-command-line-parameters-to-install-visual-studio),
including catalog selection. The existing pinned catalog is the exact-source candidate tested
here; the [VS2017 release history](https://learn.microsoft.com/en-us/visualstudio/releases/2017/vs2017-relnotes-history)
does not by itself prove binary identity. GitHub documents [cache visibility and scope](https://docs.github.com/en/actions/reference/workflows-and-actions/dependency-caching).
These are public documentation sources consulted on 2026-11-14; successful installation and
binary identity must be measured in the actual workflow run. The private handoff records the
pushed revision, run URL, observed results and remaining limits.

The raw compiler-pin file is LF-pinned in `.gitattributes`, like Python and JSON inputs.
A Windows checkout with `core.autocrlf=true` otherwise changes its raw digest even though
all four parsed binary hashes match; p128 found this in the first native target-hash CI run.
