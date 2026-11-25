# 0x32c260 BGSStandardSoundDef::GetOutputMaxDistance

<!-- tags: wall/register-schedule, abi/virtual -->

- Function: 0x32c260 BGSStandardSoundDef::GetOutputMaxDistance
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 19/40 aligned matching bytes; distance 2.5
- Attempts: 5 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The best candidate has the same twelve-instruction shape and function size, but uses a scratch register for the output-model pointer where the target reuses the receiver register. The max-distance behavior and method name are inferred, rather than established by the score. This reproduces the unresolved scratch-choice case in cookbook rule 55.

## Spellings tried that did not help

- A combined null, flag and attenuation test followed by direct returns scored 11/40, distance 4.5.
- Nested tests assigning a result initialized to the maximum finite float improved the score to 19/40, distance 2.5.
- Explicit early returns reverted to 11/40, distance 4.5.
- Const pointer references retained 19/40, distance 2.5.
- Two bounded permutation searches each exhausted their pools after 73 candidates, retaining their baseline distances of 4.5 and 2.5 respectively.
- Restoring the best nested-result body reproduced 19/40, distance 2.5. Three comparisons after the best improvement did not improve it.

## Spelling that fixed it

none
