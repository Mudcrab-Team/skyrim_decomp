# 0x17b620 reference cleanup exception state

<!-- tags: abi/exception, construct/destructor, wall/inlining -->

- Function: 0x17b620 reference cleanup exception state
- Label: GUESS(low)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: aligned code distance 0; comparator fails FuncInfo.max_state
- Attempts: 2

## What differed
The destructor spelling reproduces all 56 aligned code bytes, while the comparator rejects the exception metadata because FuncInfo.max_state differs. Two related shorter cleanup entries pass with that same destructor model.

## Spellings tried that did not help
An ordinary cleanup method omitted the destructor frame. Declaring the entry as a destructor fixed the code but did not fix the metadata here.

## Spelling that fixed it
No passing spelling was found. Keep this and the related entries at 0x18e990 and 0x55ec50 private: the latter two also reached code distance zero and still fail the exception-state check. Code distance zero is insufficient to publish a pass.
