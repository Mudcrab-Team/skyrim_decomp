# 0x5d18b0 MagicTarget::HasMagicEffectThatCausesDamage

<!-- tags: abi/exception, abi/virtual, construct/loop, method/diagnostic, wall/control-flow -->

- Function: 0x5d18b0 MagicTarget::HasMagicEffectThatCausesDamage
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 79/107 aligned matching bytes; final corrected draft 78/107
- Attempts: 4 counted

## What differed

The function constructs a damage visitor, traverses the active-effect list through virtual callbacks, and returns the visitor's result. The initial known-object callback spelling reached 79/107 but did not preserve the observed indirect dispatch shape. Final diagnostics retain branch, width and scheduling differences. A score is not equivalence.

## Spellings tried that did not help

The four scores were 79/107, 33/107, 78/107 and 78/107. An explicit visitor table with an empty destructor worsened the score and exposed the exception-state frame difference described by cookbook rule 13. A separate ordinary visitor helper restored the virtual callback and removed that diagnostic class. Widening the loop result while retaining the byte callback return left the final score unchanged. Private snapshots retain every spelling.

## Spelling that fixed it

None. The final source retains the separate visitor helper and the observed byte callback return widened for the stop comparison. Three consecutive comparisons did not improve the initial best score, so source search stopped. This is not a register-only wall; investigate the visitor and loop control flow before permutation. The nearby damage-free dispel-visitor lesson helped identify the frame issue but did not close this function.
