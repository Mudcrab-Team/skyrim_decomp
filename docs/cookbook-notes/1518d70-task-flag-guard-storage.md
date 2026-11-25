# 0x1518d70 BSLightingShaderProperty::RunWithTaskFlag

<!-- tags: abi/exception, method/binding, wall/layout, wall/register-schedule -->

- Function: 0x1518d70 BSLightingShaderProperty::RunWithTaskFlag
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); GUESS(low)
- Outcome: fixed
- Cause: struct-layout
- Best score: 80/80; comparator pass with unwind, EH data and funclets covered
- Attempts: 2 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The initial restoration guard stored both a reference to the thread-local flag and its saved value. This made the function frame larger and changed the TLS address calculation. Keeping only the saved value, and naming the thread-local flag directly in the constructor and destructor, gave the target's main function shape. The callee name and purpose remain guesses; the comparator pass establishes the compiled identity for this build, not those names.

## Spellings tried that did not help

The reference-bearing guard was 81 bytes against the 80-byte target and scored 45/80 aligned matching bytes. The saved-value-only guard reached 80/80 aligned matching bytes but initially had an unresolved cleanup-destructor reference. Marking that destructor force-inline did not remove the separately emitted exception cleanup reference.

## Spelling that fixed it

Store only the saved flag value in the scope guard and access the thread-local variable directly when saving, setting and restoring it, as suggested by cookbook rule 21. Bind the out-of-line cleanup destructor to its permitted pack reference; the unchanged comparator then passed the function, unwind information, EH data and funclets. The force-inline annotation was removed before the passing comparison.
