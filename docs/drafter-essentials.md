# Drafter essentials

Work only in the assigned checkout and task. Keep executable inputs, packs, listings, dumps,
objects and diagnostics under `.local/`; never put them in commits, PRs, issues or logs. Read
private material locally only, subject to the project authorization and your provider's terms.
Do not invent an address, name, result or evidence. A sibling is a lead, not evidence about
this build. A local pass is not acceptance: `matched` requires byte matches on two hosts and
an admitted independent review, as specified in [verification.md](verification.md).

For each function:

1. `./sr sheet 0x<rva> [--task <task-dir>]` for a prepared task; `./sr lessons 0x<rva>`
   for ranked relevant entries. Add `--tag <tag>` when a shape or wall is known;
   `--max-chars` bounds output. Omission is not proof that no lesson applies.
2. Inspect the sibling lead and its source where authorized. If an x64 lead is `exact_shape`,
   use the transplant workflow. Check community names and layout before inventing names.
3. Edit the assigned unit. Run `tools/verifier/attempt <task-dir> --model <model>`; it uses
   the configured runner. Record `--rule N` on a passing attempt when a cookbook rule fixed it.
   Bind every reported callee/data reference using the pack's references in `bind-hints.json`;
   do not edit `task.json` or `symbols.json` or invent RVAs. Compare again.
4. Keep trying while matching bytes improve. Stop on the assigned profile's consecutive
   no-improvement rule or hard cap. Compilation and binding exemptions are described in the
   full card. A score is diagnostic, not a match. Use private side-by-side diagnostics locally.
5. Before finishing run the assigned label, origin, source lint and code-rule checks. Write a
   cookbook note only for an unrecorded fix or cause; return the result and bottlenecks.

Use plausible C++; no assembly, emitted bytes, artificial dead code or control flow to force a
match. Justify permitted intrinsics and force-inlining as ordinary source decisions. Use one
class per unit and follow the include and header rules. A `noinline` definition needs a real
callee boundary. Mark actual name origins on label lines: `COMMUNITY(...)`, pinned
`SIBLING(...)`, `CRASHLOGGER_PDB(59818@<version>)`, `SYMBOLS(<source-id>)`, `EXE_RTTI`,
`OBSERVED`, or `GUESS`; add `STANDIN` where applicable. Preserve source exposure and adapted
body provenance. The full card specifies exact allowed labels and exclusions.

Read on demand:

- [drafter-card.md](drafter-card.md): precise source, label, binding and stop rules.
- [drafter-toolkit.md](drafter-toolkit.md): commands for sources, checks and reflections.
- [matching-cookbook.md](matching-cookbook.md), [near-tier-lessons.md](near-tier-lessons.md)
  and [cookbook-notes](cookbook-notes/README.md): when retrieval identifies a relevant entry,
  or when an unclassified wall needs investigation.
- [sibling-x64.md](sibling-x64.md): compiled sibling leads and their limits.
- [permuter.md](permuter.md): complete function with register or scheduling residue.
- [code-rules.md](code-rules.md): readability and admissible source details.
