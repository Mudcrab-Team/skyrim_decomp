# 0xfe82b0 BSOcclusionBox::~BSOcclusionBox

<!-- tags: abi/virtual, construct/destructor, construct/allocation, method/binding, wall/control-flow -->

- Function: 0xfe82b0 BSOcclusionBox::~BSOcclusionBox
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: branch-layout
- Best score: 95/97 aligned matching bytes before the fix; 97/97 and comparator PASS after
- Attempts: 3 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The deleting destructor initially contained an additional allocation-selection branch and an extra deallocation path. Its total size exceeded the target despite a high aligned matching-byte score. The component deletion, base vtable reset and atomic instance accounting already agreed.

## Spellings tried that did not help
A class-specific sized deallocation declaration produced the extra selection path. Binding its decorated name resolved the reference but left the same function-size mismatch.

## Spelling that fixed it
Declare the global sized deallocation function instead of a class-specific one. Keep ordinary virtual component destruction and the base destructor's atomic accounting. Define a constructor to emit the class vtable and its deleting destructor, as cookbook rule 14 describes. The unchanged comparator then passed, including unwind coverage.
