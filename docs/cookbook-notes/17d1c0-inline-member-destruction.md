# 0x17d1c0 ExtraMissingLinkedRefIDs::~ExtraMissingLinkedRefIDs

<!-- tags: construct/destructor, wall/inlining, abi/virtual -->

- Function: 0x17d1c0 ExtraMissingLinkedRefIDs::~ExtraMissingLinkedRefIDs
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: inlining
- Best score: comparator pass, 75 exact bytes plus 12 reference-checked bytes over 87 total; earlier alignment 87/87 with extra candidate operations was a failure
- Attempts: 3 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The candidate scalar deleting destructor retained an extra derived virtual-table assignment before owned array cleanup. Its function size was 97 bytes instead of 87. Complete alignment of the target bytes did not imply a match because the candidate still had extra operations.

## Spellings tried that did not help
A user-written out-of-line destructor directly released array storage and cleared its pointer and count. Moving cleanup into the Array member destructor while leaving the owner destructor defaulted out of line still retained the extra assignment. The first compile also required the C++14 static assertion message.

## Spelling that fixed it
Put cleanup into the original Array ownership helper and default the owner destructor inside the class declaration. Keep the stand-in constructor that causes the compiler to emit the virtual table. The native PC comparator passed all contract checks for the final source; this is a local candidate pass, not acceptance. No sibling body was used.
