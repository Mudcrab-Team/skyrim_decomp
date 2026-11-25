# 0x25e3b0 BGSConstructibleObject::CanBeCreatedOnWorkbench

<!-- tags: wall/control-flow, wall/flag-fold, method/sibling, sibling/fo4 -->

- Function: 0x25e3b0 BGSConstructibleObject::CanBeCreatedOnWorkbench
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: branch-layout
- Best score: 97/97 bytes; comparator PASS with unwind covered
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

A preinitialized eligibility result changed the placement of the false result and the shared exits. The permitted sibling provided a control-flow lead, not evidence about this build.

## Spellings tried that did not help

Initializing the result to false before the bench test scored 72/97 aligned matching bytes. Returning early for a null bench also scored 72/97 and changed branch placement without closing the exit difference.

## Spelling that fixed it

Declare the eligibility result without an initializer and assign it in both the bench-present branch and its else branch. Keep the conditional condition evaluation and final eligibility return. The third counted comparison passed.
