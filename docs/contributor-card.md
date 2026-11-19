# Contributor drafting card

Use `./sr` (Windows: `.\sr.cmd`) in your own clone: `go --drafted-by "<person>, assisted by
<model>"`, edit the two source files it creates, `compare`, then `submit --dry-run` and `submit`.
Open a PR that touches only `reconstruction/**`; checks run; the bot reviews and merges.

Aim for about 20-60 functions per PR (60 is the per-PR cap), or fewer if they are large; one
big function is a fine PR on its own. Classes can be mixed; open one PR per batch rather than one
per class, since each PR costs a full verification and merge cycle.

Read only the private pack named by the helper, after the owner has agreed to model exposure.
Never post listings, pseudo-C, Ghidra projects, bytes, objects, raw diagnostics or paths. Keep the
skeleton's short header (below) and fill the `Code origin:` placeholder truthfully in each file,
including adaptations and sources. Community headers are
hypotheses, not binary proof. Never write `asm`, `##`, `#pragma` (except `once`), byte arrays or
`\x` strings, and never edit verifier inputs, tools, flags or another unit to force a pass.

For FNV reuse use `SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)` and cite each reused
body in a `Sibling source: momusdigital/fnv_decomp@91e1b6e8 <path>:<line>` header line. Another
game proves no Skyrim offset, layout or behavior. Follow LEGAL.md and PROVENANCE.md.

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
`Sibling source:` and `0x<rva> <Name>` lines do not count; keep the rest to 6 lines or fewer. The
PR check fails a new or changed header that is longer or holds licence text.

Source rules:
- A label line is `// <names>: <LABEL>`; LABEL is `COMMUNITY(<owner>/<repo>@<rev>, <licence>)`,
  `GUESS(low)`, `EXE_RTTI`, `OBSERVED`, or `STANDIN` plus one of those. One label per line.
- Includes: own header `#include "X.h"`; shared headers by reconstruction-root path such as
  `"<area>/Y.h"`, for example `"skyrim_shared/forms/TESForm.h"`. Parent steps and host paths are refused.
- Declare, do not define, a function the target calls; `compare` binds the call.
- Write assignments in the order the listing stores them; keep a repeated null test as a repeat read.
- `static_assert` needs a message.
- A tail jump (`JMP <function>`) is `return Callee(...);` as the last statement.

Diagnostics: read `functions[].reason`, sizes, `first_mismatch` and `hint` from `compare`. An
unbound symbol needs the helper's bind hint, using an RVA from your own pack. A compile or include
failure is not comparison evidence. Under `cheap`, stop after 3 attempts without an improvement in
matching bytes (hard cap 6 comparisons); under `full`, 4 and 10. Keep the source and the sanitized
reason when you stop.

A local PASS is a candidate, not acceptance: the project confirms on two hosts and one review
approves the source before a function counts as `matched`. Ask once before reading listings or
pseudo-C; see [the guide](contributing-agent.md).

## Mapping-only PRs

A PR that only names functions touches `data/progress.json` and, optionally, new `findings/*.md`:

- Append entries to `functions` only: status `mapped`, the existing entry fields, no `report` or `matched`; change
  nothing else in the file and keep its layout. Add no RVA that is already present.
- Each entry's `evidence` is a findings file that exists; a guessed name has `GUESS(` in `name_source`.
- Leave out `docs/progress.svg` and `reconstruction/INDEX.md`; the bot regenerates them after the merge.
- The `mapping` check and `tools/mapping_check.py` run these rules; one review checks names, evidence and that
  nothing is game-derived. No host runs, and no function can become `matched` this way.

Stuck? Open an issue with `gh issue create --template contributor-help.yml --label from-agent` (RVA and name only, no listings); see [the guide](contributing-agent.md#getting-help).
