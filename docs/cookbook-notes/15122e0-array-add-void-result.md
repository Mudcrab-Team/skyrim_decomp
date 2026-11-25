# 0x15122e0 BSTArray<NiPointer<BSLight>>::Add

<!-- tags: wall/register-schedule, construct/constructor, abi/exception -->

- Function: 0x15122e0 BSTArray<NiPointer<BSLight>, BSTArrayHeapAllocator>::Add<BSLight*>
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: register-allocation
- Best score: 102/102 from 93/102
- Attempts: 3

## What differed
Only the registers holding the new index and the buffer pointer differed. The target overwrites eax with the buffer load, which
means the index is not the return value: the function returns nothing.

## Spellings tried that did not help
Writing the element address as `&buffer[index]`: identical output.

## Spelling that fixed it
Give the converting `Add<U>` overload a `void` result. The index no longer stays live in eax, and the allocator picks the
target's registers. Look for a clobbered return register before spending time on register spellings.
