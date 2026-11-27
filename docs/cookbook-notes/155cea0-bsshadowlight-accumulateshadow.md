# 0x155cea0 BSShadowLight::AccumulateShadow

<!-- tags: method/diagnostic, wall/register-schedule -->

- Function: 0x155cea0 BSShadowLight::AccumulateShadow
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: integer-width-or-cast
- Best score: 609/611
- Attempts: 10

## What differed

Everything matches except one zero in a select that feeds a byte store: the target clears the full register before storing its low byte, the candidate clears only the low byte. The size is equal.

## Spellings tried that did not help

A byte local, an int local, a uint8 member with a direct ternary store (stores move into the arms, worse), an int compare on a widened local (materialises the zero from another register), a small inline helper returning uint32 (same split stores), an unsigned local, a bool member with a bool local, an explicit narrowing cast, separate if and else assignments and re-reading the pointer in each conditional all keep the byte-wide clear.

## Spelling that fixed it

None.
