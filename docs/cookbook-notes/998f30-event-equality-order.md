# 0x998f30 MapMoveHandler::Function998f30

<!-- tags: abi/virtual, wall/register-schedule -->

- Function: 0x998f30 MapMoveHandler::Function998f30
- Label: GUESS(low)
- Outcome: fixed
- Cause: operand-order
- Best score: PASS, 41/41 code bytes; first draft 31/41 aligned bytes
- Attempts: 3

## What differed
The handler compares the interned event name returned by a virtual query with the named cursor event in a saved singleton pointer. The first expression put the virtual query on the left of equality. Its value-load and comparison operand order differed from the target. The alignment suggestion mentioned a field offset, but the cursor field already agreed with the community declaration and local observations.

## Spellings tried that did not help
The query-first equality compiled but did not match. No alternative offsets, artificial fields or register-search variants were needed. Declaration and provenance cleanup required a final comparison without changing the successful expression.

## Spelling that fixed it
Keep the singleton pointer in a local before the virtual query and put its cursor field on the left: `events->cursor.data == event->QUserEvent().data`. This closed the mismatch on the second comparison; the third comparison confirmed the final labelled source.
