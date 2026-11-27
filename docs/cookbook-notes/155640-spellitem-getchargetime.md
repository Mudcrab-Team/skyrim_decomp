# 0x155640 SpellItem::GetChargeTime

<!-- tags: construct/bitfield, construct/loop, construct/switch, method/diagnostic, method/sibling, sibling/fo4, wall/constant, wall/control-flow, wall/flag-fold, wall/layout, wall/register-schedule -->

- Function: 0x155640 SpellItem::GetChargeTime
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: struct-layout
- Best score: 306/306 exact
- Attempts: 7

## What differed

An auto-calculated spell takes the largest per-effect charge time over an array of effect pointers; the compiler
unrolls the loop by four. Three differences, in the order they showed: the early return for the hand-made case was
placed first where the target keeps it at the end, the flag test on bit 24 of a 32-bit flag word was a dword test
where the target tests one byte at the member's fourth byte, and finally one scratch register in the remainder loop.

## Spellings tried that did not help

- The sibling's early return `if (!IsAutoCalc()) return chargeTime;`: the short path comes first in the output.
- A 32-bit bit-field for bit 24: the compiler merges it back into a dword test.
- `(flags >> 24) & 1` on a 32-bit member: a dword test with an immediate.

## Spelling that fixed it

Put the loop inside `if (IsAutoCalc()) { ... return slowest; } return chargeTime;`. Declare the flag word in the
effect-setting stand-in as three bytes followed by a one-bit `std::uint8_t` bit-field (cookbook rule 52 with a
byte-sized base type), so the test is a byte test. The register residue went to the permuter, whose winner was
only the sibling's own spelling: no local for `effects[i]->baseEffect`, the chain written out at each use.

```cpp
std::uint8_t flagsLow[3];    // 00
std::uint8_t flagBit24 : 1;  // 03
std::uint8_t flagsHigh : 7;  // 03
```
