# 0x7e9b40 Explosion::~Explosion

<!-- tags: abi/exception, abi/virtual, construct/destructor, wall/control-flow -->

- Function: 0x7e9b40 Explosion::~Explosion
- Label: GUESS(low); COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 84/86 matching bytes; weighted distance 5.5; candidate size 106, target size 86
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The candidate duplicates the pointer and capacity reset and its epilogue on the borrowed-storage
path. The target shares that cleanup tail. The aligned behaviour check reported no differing
values, but the size and control flow still fail comparison. The assigned Explosion owner remains
a tentative name for this array-cleanup routine, not an independently established class identity.

## Spellings tried that did not help
- A reset guard confined to the owned-storage branch, following cookbook rule 67's nearby example.
- A direct conditional allocator call followed by common reset statements.
- A reset guard spanning the whole destructor.
All measured comparisons retained 84/86 matching-byte progress and distance 5.5. The fourth
comparison included the final provenance and declaration placement fixes and reproduced the failure.
Lesson retrieval suggested exception-state and shared-tail causes but did not close the routine.

- Structural pass: an early return on the borrowed-storage branch under a whole-body guard duplicates the reset on both exits and grows to 106 bytes (distance 5.5, same as before); cookbook rule 67's owned-branch guard is the other known shape, and neither shares the reset tail the target has.

## Spelling that fixed it
none. Stop after three consecutive comparisons without improvement; preserve the failed sources
privately. The residue includes duplicated cleanup and epilogue control flow, so it is not solely
register allocation or scheduling.
