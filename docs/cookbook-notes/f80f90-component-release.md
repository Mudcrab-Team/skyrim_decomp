# 0xf80f90 NiLookAtInterpolator::GetSequenceInterpolator

<!-- tags: construct/loop, abi/virtual, wall/callee -->

- Function: 0xf80f90 NiLookAtInterpolator::GetSequenceInterpolator
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 178/178 aligned matching bytes
- Attempts: 4 counted comparisons; first byte pass on comparison 2

## What differed
The first candidate released a component's final intrusive reference through a deleting destructor. The target invokes the reference-counted object's separate deletion virtual, which takes no deletion-mode argument. This left the candidate four bytes larger and introduced a virtual-slot and argument-setup difference.

## Spellings tried that did not help
A direct delete expression was the initial spelling and reached 156/178 aligned matching bytes. Two further comparisons after the first byte pass verified completed provenance headers and consistent declarations; they did not represent additional compiler-search variants.

## Spelling that fixed it
After the atomic reference decrement reaches zero, call the object's DeleteThis member. The second comparison matched all 178 bytes. The final comparison also passed after the source metadata was finalized. This is a concrete instance of cookbook rule 5: an unexpected live argument can indicate a wrong callee declaration or virtual operation.
