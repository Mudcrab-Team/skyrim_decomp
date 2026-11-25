# 0x250390 TESRegionDataGrass::Function250390

<!-- tags: abi/virtual, abi/calling-convention, wall/callee -->

- Function: 0x250390 TESRegionDataGrass::Function250390
- Label: GUESS(low)
- Outcome: fixed
- Cause: calling-convention
- Best score: 55/55 aligned bytes; all contract v2 checks passed on one host
- Attempts: 4

## What differed

The observed body obtains an object through one virtual call, invokes another virtual operation
on that object with the caller's argument and a constant mode, then returns the object from the
first call. The first candidate instead returned the second call's result, so the final operation
became a tail call. Preserving the lookup object fixed that lifetime, but initially omitted the
operation's additional unsigned mode argument. The virtual interface names, pointer roles and
mode meaning remain guesses; the match establishes emitted code, not those names.

## Spellings tried that did not help

- Returning the final call's result with two forwarded pointer arguments measured 14/55 bytes;
  the candidate was 48 bytes against the 55-byte target.
- Saving the lookup result, forwarding one argument, and returning the saved object reached
  42/55 bytes with a 49-byte candidate.
- Also forwarding the argument to the initial lookup retained 42/55 bytes. That extra lookup
  parameter was removed from the final conservative interface.

## Spelling that fixed it

Save the first virtual lookup's result, invoke the second operation with the incoming pointer
and unsigned mode value 2, then return the saved result. This measured 55/55 bytes on compare 4.
The independently compared companion at 0x252850 passed with the same spelling on its first compare.
All failed candidates and reports remain private. This is one-host candidate evidence, not acceptance.
