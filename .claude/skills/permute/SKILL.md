---
name: permute
description: Run bounded permutation searches on a reconstructed function that is complete but below 100%, keep several distinct high-scoring compiler states, and translate what they reveal into authentic source changes. Use for a diagnosed register/schedule residue, when asked to search for higher-scoring states, when several walls need permuter classification, or when a disposable exact state must be understood rather than copied.
---

# permute: search, then explain

## Repository adapter (skyrim-research)

Source: lemiur/Game-Decompilation-Skill-For-Claude@f49d2153f8ad9279262a720c88b5d337e7c63534, CC-BY-4.0, modified for this repository; see [NOTICE.md](NOTICE.md).

This repository replaces the generic project adapter. Where this skill and `AGENTS.md` differ, `AGENTS.md`
wins.

| generic verb | here |
|---|---|
| `build`, `match`, `diff` | `tools/verifier/attempt .local/tasks/<task-id>` (compile, bind, compare; read `attempts/<NNN>/0x<rva>/side-by-side.txt` locally); `./sr compare` for a contributor clone |
| `gate` | `tools/compare.py` report: the only evidence of a byte match |
| `disasm`, `xref`, `class` | local Ghidra/decompiler output under `.local/` (a hint, never source) |
| `rules` | header and unit rules in `docs/drafter-card.md`; `tools/check.py --staged`; recipes in `docs/matching-cookbook.md` |
| permuter | `tools/verifier/permute.py`, see `docs/permuter.md` |

Evidence rules: private inputs, disassembly, decompiler output and byte dumps stay under `.local/` and never enter
commits, PRs, issues or logs. Name evidence uses the labels in `PROVENANCE.md` (`EXE_RTTI`, `COMMUNITY`,
`SIBLING(...)`, `CRASHLOGGER_PDB(...)`, `SYMBOLS(...)`, `OBSERVED`, `GUESS`). Do not upload game-derived material
to a cloud service. A byte match is a candidate until two hosts match and one Reviewer approves
(`docs/verification.md`). Use the attempt budget from the task brief. Do not create worktrees or commit in a
shared checkout unless the brief says so.

Terms below that this repository does not define (`MATCH-PENDING`, `ORIGINAL-ASM`, the `decomp-code-rules` R-numbers,
score ledgers, `RULE-EXCEPTION`, `helper-recovery`) come from the upstream project; treat them as general
guidance on keeping source authentic, and report in the form the brief names.


Permutation is an evidence loop that comes *after* reconstruction and wall classification (`matcher`,
`wall-identifier`). The objective remains retail's exact structure, not the highest fuzzy spelling. Never keep
generated declarations, fake locals, `volatile` carriers or unexplained source distortions.

## Choose candidates

- Derive candidates from the build rather than a hand-kept list: complete functions below 100% whose first
  divergence is register/schedule.
- Exclude EH funclets and other compiler-generated code unless you are investigating them on purpose.
- **Unchanged functions that dropped below a proven exact:** good for replaying compiler state.
- **High-scoring functions never proven exact:** good for quick pattern discovery.

## Run several islands and keep several distinct states

- Search from several independent starting points (islands; 16–32 is a reasonable start), and keep a frontier of
  the best few *distinct* states (about 4). Keep going after an exact result, so that useful alternatives are kept.
- States differ only when their normalised instructions and ordered-relocation identities differ. Different
  source text producing the same state is one solution.
- Rank by score first, then by distance in size and relocation count. Treat topology as a separate structural clue.
- Increase islands or depth only after inspecting the previous frontier.

## Inspect the frontier

For each of the best three or four distinct states:

1. Find its first real divergence from retail.
2. Compare what moved across the frontier: call set, branch skeleton, operand order, live range, stack slot,
   register or relocation identity.
3. Read the callers, callees, types, storage and authored function before proposing an explanation.
4. State the hypothesis in source terms:
   - corrected ownership or lifetime;
   - declaration order;
   - first use after a call;
   - control-flow shape;
   - an inline boundary.

Some frontiers belong to other passes:
- **Referent changes:** back to identity evidence.
- **Call-set changes:** inline reconstruction.
- **Branch or return changes:** CFG reconstruction.

Only a proven register/scheduling residue is the permuter's to break.

## Apply one source A/B and repeat

- Implement only an evidence-backed, semantically defensible change. Never copy a disposable exact state's
  machinery into source.
- Check it with `match <unit>`, then rerun the search so that the next frontier starts from the improved
  reconstruction.
- An exact candidate closes the search only when the score, the extent, the full decoding and the ordered
  relocation identity all pass. A sub-100 improvement is a clue, not a reason to commit.
- Keep correct modelling changes even if an unrelated fuzzy score moves; the gate judges them.

Searches run no test suites; test the permuter only when you change it. Record a genuinely reusable compiler
mechanism in the project's pattern notes, with A/B evidence. No campaign logs and no per-function closure entries.
Keep tooling, documentation and source changes as separate focused changes.
