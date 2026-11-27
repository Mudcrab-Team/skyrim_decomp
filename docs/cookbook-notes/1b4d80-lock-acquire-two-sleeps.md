# 0x1b4d80 BSSpinLock::Lock

<!-- tags: wall/register-schedule, construct/loop, wall/control-flow -->

- Function: 0x1b4d80 BSSpinLock::Lock (the same acquire is inlined into 0x150dbf0, 0x1539b10 and 0x98a3c0)
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 200/200 bytes, 50/50 register uses agree after renaming; only two callee-saved registers swap
- Attempts: 7

## What differed
The earlier note stopped at 62 of 200 aligned bytes because the acquire was written with the sleep delay as a value (`Sleep(spin < limit ? 0 : 1)`),
which the compiler turns into a select and a conditional move, and with the compare-exchange tested directly. The target has neither: each exchange
result is stored in a flag and the flag is tested, and the sleep phase has two sleep calls that the compiler merges into one shared call with the delay
loaded on each side. With that shape the draft is the same size as the target and every instruction matches. What remains is that `this` and the sleep
spin counter take each other's callee-saved registers.

## Spellings tried that did not help
- Delay as a variable set in an if/else, or a ternary: a conditional move and a longer function (208 bytes).
- Counter and attempt count declared in either order, both before the thread-id call, the attempt count copied from the spin counter, the spin counter
  declared inside the sleep branch: the same swap, or 183 to 184 bytes when the zero is no longer shared between the two counters.

## Spelling that fixed it
none for the registers. The shape that gets the size right, which the inlined copies in the shadow functions need as well:

```cpp
bool acquired = _InterlockedCompareExchange(&lockCount, 1, 0) == 0;
if (!acquired) {
    do { ++attempts; _mm_pause(); acquired = _InterlockedCompareExchange(&lockCount, 1, 0) == 0; }
    while (!acquired && attempts < a_pauseAttempts);
    while (!acquired) {
        if (spinCount < 10000) { ++spinCount; Sleep(0); } else { Sleep(1); }
        acquired = _InterlockedCompareExchange(&lockCount, 1, 0) == 0;
    }
    _mm_lfence();
}
```
