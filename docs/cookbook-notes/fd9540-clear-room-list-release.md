# 0xfd9540 BSPortalGraphEntry::ClearRoomAccumList

<!-- tags: construct/destructor, abi/exception, wall/register-schedule -->

- Function: 0xfd9540 BSPortalGraphEntry::ClearRoomAccumList
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 91/111 aligned matching bytes before the final change, then local comparator PASS
- Attempts: 3 comparisons to first pass, 4 including the declaration check

## What differed

The room list destroys its references in order and retains the backing allocation. With the destruction loop in place, the candidate reached the target size, but the register saves used different stack slots and unwind comparison failed.

## Spellings tried that did not help

Testing the old count directly inside the release helper left the saves one slot early. The original loop also widened the array size before checking whether there was any work.

## Spelling that fixed it

Test the array size before widening it to the destruction count. In the room release helper, keep the decremented reference count in a named unsigned local and delete the room when that count reaches zero. Cookbook rule 29 closed the remaining stack and unwind differences.
