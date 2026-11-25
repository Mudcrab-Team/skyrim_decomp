# 0xfe9f00 BSPortal::CreateClone

<!-- tags: construct/constructor, construct/destructor, abi/exception -->

- Function: 0xfe9f00 BSPortal::CreateClone
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 163/163 aligned matching bytes
- Attempts: 7 comparisons, first local pass on comparison 4

## What differed

The clone allocated and copied both rooms in the right order. A raw shared-node pointer left out the exception-state transition after base construction.

## Spellings tried that did not help

A reference wrapper with a null initializer and an external destructor left the body one byte short. Resetting through a temporary reference also left the transition absent.

## Spelling that fixed it

Model the portal-owned node as an intrusive reference. In the reset path save the previous node, clear the field, and issue the final release only if the reference count reaches zero. The compiler removes the redundant clear of an already empty reference while retaining the construction unwind states.
