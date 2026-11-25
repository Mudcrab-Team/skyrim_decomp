# 0x3e6620 TESRace::GetDefaultHeadPart

<!-- tags: construct/loop, wall/register-schedule, abi/calling-convention, method/sibling, sibling/fo4 -->

- Function: 0x3e6620 TESRace::GetDefaultHeadPart
- Label: SIBLING(fo4-private@1b765c70, author-permission); COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 4/72 aligned matching bytes on the second comparison; final draft distance 12.0; permutation best distance 11.5, no pass
- Attempts: 5 counted comparisons; separate one-worker search scored 89 candidates

## What differed
The sex-indexed face-data lookup scans head parts until the requested type is found. The target assumes each stored head-part pointer is non-null and preserves the previous result through a conditional selection. The final handwritten draft has the observed pointer and type accesses, but retains an extra saved register and changes the loop's register assignment. Broad register renaming makes the aligned matching-byte metric especially low here. A clean behavior tally does not establish equivalence.

The naming and search lead came from the permitted game-code sibling at its pinned revision. Community declarations supplied the partial field names; target observations supplied the accessed offsets and the signed sex index. Source exposure is mixed. Confidence in the remaining register-pressure diagnosis is medium; source structure may still differ.

## Spellings tried that did not help
The first draft reset the result for every rejected candidate. Restoring the persistent result and signed sex index reached 4/72 aligned matching bytes. An explicit conditional selection and an ordinary inline selection helper produced identical compiler states while retaining an unsupported null-element path. Removing that path reduced distance to 12.0 but left the saved-register overhead. The final ordinary comparison was the third without an increase over the best aligned matching-byte score.

The required one-worker permutation search stopped on patience after 89 candidates, improving distance from 12.0 to 11.5. It found no comparator pass, and its disposable best source was not applied. Cookbook rule 44 motivated the helper but did not close this function. All failed sources and reports remain private.

## Spelling that fixed it
None. The final handwritten draft and the separate permutation frontier are retained for further diagnosis; no match or acceptance is claimed.
