# 0x5d51c0 MagicItem::GetCostActorValue

<!-- tags: construct/switch, wall/register-schedule, abi/calling-convention -->

- Function: 0x5d51c0 MagicItem::GetCostActorValue
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: switch-lowering
- Best score: 114/134 aligned matching bytes (unsupported narrow-return experiment); retained wide-return draft 92/134
- Attempts: 6

## What differed
The retained draft has the observed virtual-call set and resource selections, but the switch lowering lacks one value transfer and has register and scheduling differences. The initially Boolean casting-source parameter also used the wrong width. The highest diagnostic score came from a narrow spell-type return declaration; the target observation does not support that declaration, so it was reverted. No comparator pass was obtained.

## Spellings tried that did not help
A full-width casting-source parameter improved 84/134 to 92/134. Replacing the switch with equality disjunctions fell to 70/134. Signed and unsigned wide spell-type returns both measured 92/134. A one-worker permutation search scored 81 candidates and improved distance from 5.5 to 3.5 by narrowing the switch input, without a pass. A natural return accumulator remained at 92/134. The six-compare cap ended the search.

## Spelling that fixed it
None. Revisit the source-level reason for the switch value transfer before spending further register-allocation attempts. The narrow-return experiment is diagnostic evidence only.
