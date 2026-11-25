# 0x118990 variadic formatting wrapper

<!-- tags: abi/calling-convention, wall/inlining, wall/register-schedule -->

- Function: 0x118990 variadic formatting wrapper
- Label: GUESS(low)
- Outcome: fixed
- Cause: inlining
- Best score: PC comparator pass, 88-byte extent including unwind
- Attempts: 4

## What differed
A direct common-stdio call lost a saved argument register. Standard formatting wrappers preserved the argument lifetime but added an option bit; applying another negative-result clamp duplicated the final test.

## Spellings tried that did not help
Calling the common function directly; using vsnprintf; using _vsnprintf and clamping its already-clamped result.

## Spelling that fixed it
An inline helper calls __stdio_common_vsprintf with the unchanged options word and clamps its own result once. The variadic entry creates the argument list, calls that helper, ends the list and returns its result. Four source variants were compared; the last passed on the PC. This establishes one-host candidate evidence only.
