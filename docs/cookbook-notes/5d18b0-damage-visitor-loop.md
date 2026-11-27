# 0x5d18b0 MagicTarget::HasMagicEffectThatCausesDamage

<!-- tags: abi/exception, abi/virtual, construct/loop, method/diagnostic, wall/control-flow -->

- Function: 0x5d18b0 MagicTarget::HasMagicEffectThatCausesDamage
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 107/107 code bytes; comparator PASS, unwind covered
- Attempts: 2 counted comparisons after the structural reading

## What differed
The earlier draft seeded the visit loop with a zero result and ran while the result was not one. The target seeds a 32-bit result from the list itself (one when the first node exists and carries an effect, zero otherwise), then walks while the node exists and the result is exactly one. Accept's result is a full 32-bit value, not a byte.

## Spellings tried that did not help
- A byte result, a zero seed and a loop that continues while the result differs from one gave 79/107.

## Spelling that fixed it
Seed `std::uint32_t result = node && node->effect ? 1 : 0;` and loop `while (node && result == 1)`, assigning the 32-bit result of the virtual Accept each time. The visitor is a real polymorphic class with an inline empty virtual destructor, which supplies the exception-state slot. The same reading closes 0x5d1400 and 0x5d2da0 and brought 0x5d16d0 from 21 to 1.0.
