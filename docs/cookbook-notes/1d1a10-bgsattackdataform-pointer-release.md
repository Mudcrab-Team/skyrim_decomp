# 0x1d1a10 BGSAttackDataForm::~BGSAttackDataForm

<!-- tags: construct/destructor, method/binding, wall/callee -->

- Function: 0x1d1a10 BGSAttackDataForm::~BGSAttackDataForm
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: inlining
- Best score: 75/75 bytes; comparator PASS with unwind covered
- Attempts: 5 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The compiled destructor reloaded the smart-pointer member after decrementing the shared reference count. The target kept the same pointee through the last-reference deletion call.

## Spellings tried that did not help

Using the pointer member directly in both the decrement and deletion expressions produced 71/75 aligned matching bytes. Two earlier invocations did not compare because the plain and deleting destructors needed an explicit symbol selection.

## Spelling that fixed it

Copy the held pointer to a local, then use that local for both decrement and deletion. The second counted comparison passed; three later comparisons checked final provenance comments. The header selects the plain destructor explicitly; this selection is binding metadata, not a source workaround.
