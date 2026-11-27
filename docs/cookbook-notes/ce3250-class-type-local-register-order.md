# 0xce3250 BSReadWriteLock::LockForRead

<!-- tags: wall/register-schedule -->

- Function: 0xce3250 BSReadWriteLock::LockForRead
- Label: SpinBackoff: GUESS(low)
- Outcome: fixed
- Cause: register-allocation
- Best score: 112/112 (earlier rounds: unwind-info-mismatch with equal size)
- Attempts: 3 counted (0xce32d0: 2, PlayerCharacter::Function6d6820 0x6d6820: 10)

## What differed
Every instruction matched; only which two callee-saved registers held `this` and the spin counter
differed, which shows as an unwind-info mismatch at the start of the function.

## Spellings tried that did not help
About 45 controlled variants on 0x6d6820 and many earlier ones: plain index or pointer locals,
declaration order, `for` versus `while`, accessors, and an inline function taking the plain local by
reference. A struct holding both variables did not work either.

## Spelling that fixed it
Hold the counter as the only member of a class-type local with an inline constructor and an inline
method. The compiler allocates the member of a class-type local ahead of plain scalar locals, with
no change in instructions; give each variable that must outrank another its own such class.

```cpp
struct SpinBackoff { SpinBackoff() : spins() {} void Pause(); unsigned spins; };
void BSReadWriteLock::LockForRead() { SpinBackoff backoff; while (!TryAcquire()) backoff.Pause(); }
```
