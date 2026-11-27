# 0x150e090 ShadowSceneNode::ClearLightArrays

<!-- tags: wall/inlining, abi/exception, method/diagnostic -->

- Function: 0x150e090 ShadowSceneNode::ClearLightArrays (also 0x150e5e0, 0x150e680)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 343/343, 142/142 and 140/140 bytes with unwind and exception data on both hosts
- Attempts: 4

## What differed
All three passed on the Mac host while their draft lived in the unit that also held the callee definitions, then failed the
Windows CI hash after being moved into a pool unit. The cause was the move, not the host: the pool unit lost two things its
callers relied on. The lock release (the inline spin-lock unlock the header claimed as an adapted body) had no definition left,
so the guard destructor called it instead of inlining it; and the callees `FindActiveLight` and `QueueLightAdd` were only declared,
so the compiler no longer knew they leave their arguments alone. That kept the smart-pointer local reloaded from the stack at its
release (the target keeps the loop pointer in a register), added an exception-state entry for the unproven `FindActiveLight`
call, and made the three functions 11 to 45 bytes off.

## Spellings tried that did not help
- Local bind hints for the guard and smart-pointer destructors alone: they only silence the unresolved-symbol message.
- Comparing the moved text with the old unit by eye: the bodies were identical, so only a diff of the whole translation unit
  (which definitions it holds) showed the difference.

## Spelling that fixed it
Put the three functions in a new unit that defines `BSSpinLock::Unlock` before its first use and defines `FindActiveLight` and
`QueueLightAdd` (unclaimed) ahead of the callers, as the engine's own unit did. A unit that was merged cannot be edited without
making its records stale, so the claim lines of the three functions were removed from the pool unit (comments only, the digest does
not change) and the new unit carries them. When a Mac pass and a CI hash fail disagree on a moved function, diff the set of
definitions in the unit, not the function.
