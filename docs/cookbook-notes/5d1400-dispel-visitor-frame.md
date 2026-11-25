# 0x5d1400 MagicTarget::DispelAllSpells_140552E10

<!-- tags: abi/exception, abi/virtual, construct/loop, method/diagnostic, wall/control-flow -->

- Function: 0x5d1400 MagicTarget::DispelAllSpells_140552E10
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 49/101 aligned matching bytes initially; final corrected draft 33/101
- Attempts: 3

## What differed

The target includes an exception-state frame slot absent from the candidate. The visitor loop and callback setup also differ. A permitted game-code sibling algorithm lead confirmed a list visitor with an immediate-dispel flag; its body was not copied. The source explicitly models the observed visitor table and list fields. No score establishes equivalence.

## Spellings tried that did not help

The first draft used a continue value of one and an early empty-list return. Correcting the callback result to a byte, using stop value one, and keeping the empty-list selection before the loop reduced the diagnostic score to 33/101. This semantic correction is retained. An empty visitor destructor left that score unchanged. Every draft remains in private attempt snapshots.

## Spelling that fixed it

None. Cookbook rule 13 identifies the exception-state slot without a handler as an open triage case. The initial higher-scoring draft is evidence of a failed spelling, not a recommended implementation. Investigate the actual visitor class and cleanup boundary before further source search.
