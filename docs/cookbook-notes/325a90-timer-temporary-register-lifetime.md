# 0x325a90 BGSMusicSilenceTrack::DoUpdate

<!-- tags: wall/register-schedule, construct/float, abi/virtual, method/sibling -->

- Function: 0x325a90 BGSMusicSilenceTrack::DoUpdate
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: register-allocation
- Best score: 79/79 bytes; native comparator pass with unwind covered
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The first body had the correct 79-byte extent, reference bindings and branch shape, but three register operands differed. Alignment measured 70/79 matching bytes and classified the residue as register renaming. The duration is calculated before the virtual status query; the timer result is used only in the playing branch.

## Spellings tried that did not help
Widening the saved duration to an unsigned 64-bit local fell to 66/79. An early return with a separate 64-bit elapsed local reached 68/79. A one-job PC permutation search exhausted its useful states without improving the original distance.

## Spelling that fixed it
Keep the duration local unsigned 32-bit. Nest the timer test inside the playing-status branch, name the timer result with `const auto now = GetTickCount()`, and compare its explicitly widened value minus `playTime` against the duration. Do not introduce a separate elapsed local or invert the outer guard. This ordinary source spelling passed all comparator checks. The permitted sibling timing body was a source lead only; target clock width and field layout were checked against this build.
