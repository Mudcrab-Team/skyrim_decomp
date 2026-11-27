# 0xbafa60 BGSGamebryoSequenceGenerator::GetBlendPercentage

<!-- tags: construct/float, construct/switch, wall/register-schedule, wall/control-flow -->

- Function: 0xbafa60 BGSGamebryoSequenceGenerator::GetBlendPercentage
- Label: CRASHLOGGER_PDB(59818@2026.10.24); SYMBOLS(tesv-2013-map); SYMBOLS(fo4-pdb); GUESS(medium)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 45/58 matching bytes; weighted distance 3.5; comparator fail
- Attempts: 6 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The signed blend-mode switch and bounded float calculation are complete in the candidate. The best candidate still places the initial result copy earlier and arranges the lower-bound branch and zero-return block differently. The measured extent agrees, but the comparator does not pass. The method name is a candidate assignment from permitted symbols, not proven identity. This extends the previously open observation in cookbook rule 45 without resolving it.

## Spellings tried that did not help

- An uninitialized result with an explicit default return and two independent bound tests reached 38/58 matching bytes and distance 8.5.
- Initializing the result to one and nesting the bound returns reached 40/58 and distance 7.0.
- Omitting the default arm reached 40/58 and distance 6.5.
- A bounded single-worker permuter tried 305 candidates and reduced distance to 3.5 by inverting the upper-bound test and retaining explicit alternate returns. The corresponding measured attempt reached 45/58.
- Returning early on a negated lower-bound test and assigning the upper clamp regressed to 43/58 and distance 7.0.
- Restoring the best spelling reproduced 45/58 and distance 3.5 on the final compare. No exact candidate was found.

- Structural pass: a plain clamp (`if (r < 0) return 0; if (r > 1) return 1; return r;`) and a single-result clamp both moved the distance up (4.0 and 7.0); the target tests the lower bound with a branch to the upper-bound test and returns the zero already held in the comparison register.

## Spelling that fixed it

None. Six counted comparisons exhausted the assigned cap. Best source, all failures and the permuter history remain private; the failing reconstruction is withheld from passing-source paths.
