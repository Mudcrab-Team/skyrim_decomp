# Contributor drafting card

Use `./sr` (Windows: `.\sr.cmd`) in your own clone: `go --drafted-by "<person>, assisted by
<model>"`, edit the two source files it creates, `compare`, then `submit --dry-run` and `submit`.
Open a PR that touches only `reconstruction/**` and `docs/cookbook-notes/**`; checks run; the bot reviews and merges.
A PR that touches only `findings/*.md` (static research prose: settings, values and rules in words, no bytes,
disassembly or decompiler text) takes the same bot route after a leak scan, the `check` job and one review.
Before drafting, read `docs/cookbook-notes/` for your function's class or cause, and look the shape up in
`docs/generators.md`: a family generator may already emit it. When you add or change a generator, or land 50 or more
functions from one family, add a short family note (shape, why it matches, pitfalls) in `findings/` or as a lesson note.
**Send your lessons.** Next to your functions, send what you learned: a near-miss (what differed, what you tried), a
pass that took four or more compares (the spelling that closed it) or a compiler shape you solved. `./sr lesson <rva>`
writes the template pre-filled from your task; finish every `TODO` (fields, causes and a worked example in
`docs/cookbook-notes/README.md`), then submit it in the same PR. Words and plain C++ only, never bytes or listings;
an RVA and a name are enough. Notes credit you as co-author of the merge commit and are folded into the cookbook at the
next round. `submit` and the bot's comment remind you when a function mismatched and no note is there; tool friction
goes under "Bottlenecks" in the PR description instead.
For a function over about 1,000 bytes, or a first score
under 80 percent, also read `docs/near-tier-lessons.md`.
If a cookbook rule fixed a function, add one header line to its unit, `// Cookbook: 0x<rva> N` (or `N, M`); it does
not count against the header budget, and it feeds the rule ranking at the top of the cookbook.
**Check the sibling x64 hint first.** `./sr start` prints the closest compiled Fallout siblings (needs `./sr setup`
once) and writes them to `sibling_x64.json` in the task folder. An `EXACT SHAPE` line means the body can be
transplanted with `tools/sibling_transplant.py`, which writes the `SIBLING(...)` labels; only `compare` decides.
Stuck or unsure? Ask in [Discussions (Q&A)](https://github.com/Mudcrab-Team/skyrim_decomp/discussions/categories/q-a).

Aim for 50 to 200 functions per PR (1000 is the per-PR cap); more is fine, and one PR per family or
class is ideal. A single large function is also a fine PR on its own. Classes can be mixed. Fewer,
bigger PRs help most: each PR costs a full verification and merge cycle, and large batches have
merged cleanly in about an hour. Thank you, don't be shy.
`submit <task> <task>...` (or
`submit --all-dirty`) puts several tasks' units in one PR; `preflight` takes the same arguments.
`next --class REGEX` ranks only classes whose name matches, and `claim ... --skip-conflicts` claims
the functions nobody holds and names the others with their claim issues.
`next` offers callee-ready functions first (every callee already matched; `data/ready-queue.json`,
regenerated with `tools/ready_queue.py`); the ordering is advisory.
`data/target-hashes/contributor-target-facts.json` (from `tools/target_facts.py`) lists the committed PDB name,
prototype, size and alignment proposal per offered target, as hints only. The file is an index; the entries are in
`contributor-target-facts-part-NNN.json` beside it (`tools/target_facts.py` reads them back together).

Read only the private pack named by the helper, after the owner has agreed to model exposure.
Never post listings, pseudo-C, Ghidra projects, bytes, objects, raw diagnostics or paths. Keep the
skeleton's short header (below) and fill the `Code origin:` placeholder truthfully in each file,
including adaptations and sources. Community headers are
hypotheses, not binary proof. Never write `asm`, `##`, `#pragma` (except `once`), byte arrays or
`\x` strings, and never edit verifier inputs, tools, flags or another unit to force a pass.

Both siblings also exist as x64 ports you can compile locally (`docs/sibling-x64.md`).

For Fallout 3 (`momusdigital/f3_decomp`, CC0-1.0) the same with `SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)`
and `Sibling source: momusdigital/f3_decomp@f5bac1b5 <path>:<line>`. Read FO3 and FNV first for
engine-shared classes (names, layouts, vtable order, body shape); both are 32-bit, never byte evidence.
For FNV reuse use `SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)` and cite each reused
body in a `Sibling source: momusdigital/fnv_decomp@2b07cb3e <path>:<line>` header line. Another
game proves no Skyrim offset, layout or behavior. Follow LEGAL.md and PROVENANCE.md.

Skills in `.claude/skills/` (adapted from lemiur's Game-Decompilation-Skill, CC-BY-4.0, see each
`NOTICE.md`): `matcher` for a near-miss you are iterating on, `permute` when only register
allocation or ordering differs, `wall-identifier` when a function stalls, to classify the wall
before giving up.

## Big batches: use subagents

Don't try to do it all in one go; spawn subagents (Claude Code's Agent tool, Codex subagents or any
equivalent). Cheaper models are fine for drafting.

1. The lead agent picks one family or class and runs `start` for 50 to 150 functions.
2. It splits them into batches of 10 to 15 and gives each subagent one batch.
3. Each subagent works in its own worktree and its own new unit files, one unit per function. It
   never edits a shared header or an already matched unit, since that makes matched functions stale.
   Name each new unit `<Class>_<rva>.h` and `<Class>_<rva>.cpp` (RVA in lowercase hex, no `0x`).
4. Each subagent loops `compare` on its tasks until PASS and gives up on a function after a few tries.
5. The lead merges the passing branches into one, runs `submit --dry-run`, and opens one PR with
   `submit --all-dirty`.
6. Every subagent brief asks it to report bottlenecks and suspicious behaviour, one line each with a
   time cost (AGENTS.md, "Report bottlenecks"). The lead lists them under "Bottlenecks" in the PR
   description, or opens a `tooling.yml` issue for a step that costs more than about 5 minutes per function.

**Subagent batches are a drafting split, not a PR split.** Never open one PR per subagent, worktree or
batch of 10 to 15. Subagents never open PRs or run `submit`; only the lead does, once, for the whole
run. Split only above the 1000 cap, and never open extra PRs just to trigger checks.

Worktree and storage setup for this is in [contributor-parallel.md](contributor-parallel.md).

Read `docs/contributor-lessons.md` before your first PR: common Reviewer rejections.

Header: keep it short. The skeleton writes all of it; a `.cpp` looks like

```
// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0x1de5e0 TESActorBaseData::Unk_07
// Adapted bodies: none
#include "TESActorBaseData.h"
```

Never paste licence text, and leave out Task, Labels, Evidence, Drafted by, Recipe (unless it is
not the default) and any "a byte match shows..." disclaimer: the records and git hold them. Labels,
`Sibling source:`, `0x<rva> <Name>` and `CI hash: 0x<rva> <symbol>` lines do not count; keep the rest to 6 lines or fewer. The
PR check fails a new or changed header that is longer or holds licence text. The failure names the file, how many lines it is over and the lines that count. To fix a `header` rejection run `python3 tools/compact_headers.py --apply <files>` (per file; it changes comments only and leaves a file alone if its digest or lint would change). It keeps every `Source exposure`, `Code origin` and `Adapted bodies` line, because the digest hashes them, so it reports a file "unchanged" when the overrun is repeated copies of those lines (a second skeleton block, or a header pasted from another unit, after you added functions to a unit): keep one of each, merge their text, and delete the rest by hand.

Intake also refuses, in the files you change: codegen steering (`#pragma optimize`/`intrinsic`/`function`, `_ReadWriteBarrier`, `noinline` without a `// noinline: <evidence>` comment; R38), decompiler leftovers (`undefined`, `CONCAT44`, `SUB41`, `ZEXT48`, `SEXT48`, `CARRY4`, `SBORROW4`; R39) and comments that name a model or tool, a checkpoint id, a host path or an e-mail address (R40). The message gives the rule, line, text and fix; `docs/code-rules.md` has the full rows.

A function is claimed only by its `// 0x<rva> <Name>` line (older units also use `RVA 0x<rva>, <n> bytes`
or `compared at RVA 0x<rva>`). An address in prose, such as a callee or a global in a provenance line, is not
a claim. If a claimed RVA has no published target row yet and is a function start of the pinned build, the
bot publishes its row (hash only) and re-runs the check on your head; an address that cannot be compared
is named in the bot comment instead of being skipped.

Source rules:
- A label line is `// <names>: <LABEL>`; LABEL is `COMMUNITY(<owner>/<repo>@<rev>, <licence>)`,
  `CRASHLOGGER_PDB(59818@<version>)` (a name or layout from the generated CrashLogger output, below),
  `SYMBOLS(<source-id>)` (a member name from the sibling symbol evidence, below),
  `GUESS(low)`, `EXE_RTTI`, `OBSERVED`, or `STANDIN` plus one of those. One label per line.
- Includes: own header `#include "X.h"`; shared headers by reconstruction-root path such as
  `"<area>/Y.h"`, for example `"skyrim_shared/forms/TESForm.h"`. A relative path with `..` is fine when it
  resolves to a regular file inside the repository; host paths and paths that leave it are refused.
- `compare` builds with the recipe the unit's own `Recipe:` line names (the first `reconstruction/recipes/*.json`
  path in the source), as CI does, and with the task's recipe when the unit names none.
- PDB layouts: when `start` prints `PDB layout`, read that class header for field names, offsets and bases. A unit that
  already declares the class takes just the members it needs into its own header (a second definition of the class
  in one include closure fails); a unit that does not may include it as `"generated/crashlogger_pdb/types/X.h"` with
  `Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json`. Label a name or layout taken from it
  `CRASHLOGGER_PDB(59818@2026.10.24)`; it is a guess until `compare` matches. `PDB prototype` gives the signature
  the PDB records (the first parameter of a method is its `this`, often another class), and `PDB boundary warning`
  means a claimed RVA is inside a PDB function, not at its start.
- Declare, do not define, a function the target calls; `compare` binds the call.
- Write assignments in the order the listing stores them; keep a repeated null test as a repeat read.
- `static_assert` needs a message.
- A tail jump (`JMP <function>`) is `return Callee(...);` as the last statement.

Diagnostics: read `functions[].reason`, sizes, `first_mismatch` and `hint` from `compare`. A compile or include
failure is not comparison evidence. Under `cheap`, stop after 3 attempts without an improvement in
matching bytes (hard cap 6 comparisons); under `full`, 4 and 10. Keep the source and the sanitized
reason when you stop.

A local PASS is a candidate, not acceptance: the project confirms on two hosts and one review
approves the source before a function counts as `matched`. Ask once before reading listings or
pseudo-C; see [the guide](contributing-agent.md).

## When a function needs a hint

`compare` and intake find each function's decorated symbol from its `// 0x<rva> Class::Method` header
line and community name, with no hint, for: const and non-const or static and member overloads (told
apart by size, then by the published target hash), `Class::Ctor`/`Class::dtor` names, deleting
destructors and their adjustor thunks, and overrides named for their base class. Add a hint only when
`compare` says UNBOUND:

- The unit defines the function under another name (a `Slot195` for `Unk_C3`): write that name on its
  header line, `// 0x7ddfd0 ArrowProjectile::Slot195`.
- Same-named overloads of equal size and hash: put the signature on the header line,
  `// 0x1900a0 NiAVObject::GetCollisionObject() const`, or paste the `// CI hash: 0x<rva> <symbol>`
  line `compare` prints. Both are read by every host; `bind-hints.json` stays on your machine.
- A thread-local: name the variable `..._tls_0x<offset>` (or a local `tls:` hint).

## If you can't match it

Stop on the profile's numbers (the card above), then keep what you learned instead of losing it:
`./sr release 0x<rva> --reason "<one line>" --category <control-flow|register-schedule|inline-set|layout-unknown|eh-frame|callee-missing|signature-wrong|other> --tried "<one short try>" --tried "..." --still-differs "<in words>" --suspected-cause "<one sentence>"`
releases the claim and writes `data/giveups/<build id>/<rva>.json` with those words, the best similarity of your last compare, your model and `./sr`. The file is committed by your next `submit`
(a PR may carry it with units or notes, or alone); it is words and numbers only, and the leak scan and `tools/giveup.py check` refuse instructions, bytes and paths.
The best source stays in your task folder. If the near-miss has a cause the cookbook does not cover, write a lesson note (`./sr note`) and add `--note docs/cookbook-notes/<file>.md`, so the record points at it.
The next person who runs `./sr next`, `claim`, `start` or `facts` for that function sees the records first and does not repeat your tries; `python3 tools/giveup.py show 0x<rva>` prints them.
A record is a lead, never evidence.

If `compare` fails on a function whose image has no exception frame, it also retries the unit without `/EHsc` and prints `MATCH (under <flags>)` with the `Recipe:` line to add;
the verdict stays a failure until the unit names that recipe (`docs/verification.md`, "Alternative flag sets"). `--no-retry` skips it.

## Verdicts

The bot's one sticky comment on your PR ends with a table that names a verdict per function that was not
accepted, so you can see whose move it is. Accepted functions and ones that already failed before your PR are
not named. A strike is recorded only by a maintainer, from a completed CI hash comparison that contradicts a
function your PR explicitly claims; three active strikes stop automatic intake (`tools/contributor_standing.py`).
The table below is generated from `tools/verdicts.py`.

<!-- verdicts:start -->
| Verdict | What happened | Strike | Next step |
| --- | --- | --- | --- |
| `matched` | Byte match on both hosts and one approved review. | none | Merged and recorded; nothing to do. |
| `mismatch` | The compiled function differs from the game's bytes on a host that finished the comparison. | counts when an explicit claim is contradicted by the completed CI hash comparison | Run `./sr compare`, read the first mismatch and the hint, change the source and push. |
| `compile_error` | Nothing was compared: the unit did not compile, an include did not resolve, or no symbol bound to the RVA. | contributor's fault, no ledger entry today (the strike ledger excludes compile and setup errors) | Compile it locally with the unit's recipe (`./sr compare`), fix the error, include or binding and push. |
| `unfit` | Both hosts byte-matched the function on its own, but not as part of its unit file or the others in the PR: a mechanical check on the unit (lint, undeclared adapted body, or a binding that does not equal the unit as pushed) refused it before any review. | none | Keep the function in a unit of its own or fix the finding the comment names; merge main if the branch is behind. Left alone, it goes back to the pool unclaimed. |
| `needs_review` | A failure on our side: toolchain, verifier host, CI hash infrastructure, or a record that could not be written. The function was not judged. | none | Nothing to do: the bot re-verifies the head automatically, and a maintainer looks if it repeats. |
| `refused_rules` | The unit breaks a mechanical source rule (R38 codegen steering, R39 decompiler leftovers, R40 comment contents) and was refused before any compare. | counts only if the rule was in docs/code-rules.md at the PR's base; none for a newer rule | Fix the line the finding names and push. |
| `review_rejected` | Both hosts byte-matched, but the review did not approve the source. | none | Read the notes under the function, fix the ground they name and push. |
| `debt` | The function already failed to match before this PR; it never blocks, is not recorded and is not named in the comment. | none | Nothing is asked of this PR. |
| `held` | The whole PR was held (a leak finding or a regression of an accepted function); this function was not judged. | none | Read the message above the table, fix what it names and push. |
<!-- verdicts:end -->

The comment's own lines under "Not accepted yet" keep their wording; the table adds the verdict, the strike
effect and the next step. A PR held before any compile for an R38-R40 finding says the same for `refused_rules`.

## Recommended: CrashLogger PDB names

`reconstruction/generated/crashlogger_pdb/` holds names and layouts generated from the community "CrashLogger PDBs"
(https://www.nexusmods.com/skyrimspecialedition/mods/59818); `next` shows a function's name from it as a suggestion.
Label each name or layout you take `CRASHLOGGER_PDB(59818@2026.10.24)`, one label per line. It names functions; it
does not prove them, so `compare` still decides. Downloading the mod (`ae17` variant, 1.7.104) is optional, only
to refresh the output: keep it under `.local/`, e.g. `.local/pdb/SkyrimSE.pdb` (or `SR_CRASHLOGGER_PDB`), and
`llvm-pdbutil dump -publics` lists its publics. Never commit the `.pdb`.

## Optional: sibling symbol names

`data/symbol-names.json` and `data/name-corroboration.json` hold class-member names and object-file names read
from five sibling-build symbol files (a 2013 linker map of this game, a Fallout 4 program database, three Xbox 360
Fallout: New Vegas program databases; `findings/sibling-symbol-files.md`). They are candidates for what a class's
members are called, never which function is which. A name a unit takes from them carries `SYMBOLS(<source-id>)`
with `<source-id>` one of `tesv-2013-map`, `fo4-pdb`, `fnv-x360-pdb`, one label per line, naming the source that
has the member. The files themselves are never committed; `compare` still decides. For the 2013 map and the Fallout 4 PDBs
the maintainer widened use to any extent (prototypes, order, layouts, vtables; downloads and rules in
`docs/contributing-agent.md`, "2013 map and Fallout 4 PDB"; only `.map`/`.pdb`, no bundled executables, never
commit a dump or excerpt). The Xbox 360 files stay name-only, and no map address goes into a unit.
`./sr facts 0x<rva>` is step 1 of every function: it prints every PDB fact held for it (CrashLogger prototype and
size, map name, prototype and object file, Fallout 4 layout) with the label lines; `./sr setup` checks the downloads. `start` prints up to 12 of these names for the started class, each with its
`<source-id>`, as candidates only.

## Mapping-only PRs

A PR that only names functions touches `data/progress.json` and, optionally, new `findings/*.md`:

- Append entries to `functions` only: status `mapped`, the existing entry fields, no `report` or `matched`; change
  nothing else in the file and keep its layout. Add no RVA that is already present.
- Each entry's `evidence` is a findings file that exists; a guessed name has `GUESS(` in `name_source`.
- Leave out `docs/progress.svg` and `reconstruction/INDEX.md`; the bot regenerates them after the merge.
- The `mapping` check and `tools/mapping_check.py` run these rules; one review checks names, evidence and that
  nothing is game-derived. No host runs, and no function can become `matched` this way.

`next`, `claim` and `start` accept a function of the published target-hash list with no inventory entry; the bot
creates its `mapped` entry when it records the match, so no mapping PR is needed for it.

Stuck? Open an issue with `gh issue create --template contributor-help.yml --label from-agent` (RVA and name only, no listings); see [the guide](contributing-agent.md#getting-help).
