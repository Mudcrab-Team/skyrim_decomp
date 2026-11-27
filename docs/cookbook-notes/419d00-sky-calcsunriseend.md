# 0x419d00 Sky::CalcSunriseEnd

<!-- tags: method/diagnostic -->

- Function: 0x419d00 Sky::CalcSunriseEnd
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 67/67
- Attempts: 2

## What differed

The candidate loaded the flag word into a register, tested it with a bit test and cleared it with a bit reset. The target tests the member in memory, stores the cached float, then clears the flag with a memory and. The candidate stored the float result into a file-static global and the compiler kept the flag word in a register across that store.

## Spellings tried that did not help

Memory operand spellings of the flag test (mask, bit-field, volatile) were not needed. Sizes 68 against 67 until the global changed.

## Spelling that fixed it

Give the cached float a global with external linkage (`float g_sunriseEnd;` not `static float`). The compiler then assumes the store may alias `this->flags`, reloads the word from memory and emits test and and on the member. The same unit closed 0x419d50.
