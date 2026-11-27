# 0x1510940 ShadowSceneNode::BuildSharedCompoundFrustum

<!-- tags: wall/control-flow, method/binding -->

- Function: 0x1510940 ShadowSceneNode::BuildSharedCompoundFrustum
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: branch-layout
- Best score: 537/537
- Attempts: 5

## What differed
The first draft had the right size but every call target was wrong: nine helper addresses had been typed with the section-relative offset from the listing comment instead of the image address minus the image base (all off by one page). After the hints were corrected the sizes and calls matched and only two things were left: the stack-local sentinel pointer was set up before the first room test instead of inside both arms, and the final choice between the two parent frustums was laid out with the combined case as the fall-through instead of the single case.

## Spellings tried that did not help
- Setting the open-side pointer once before both room lookups: the compiler hoisted the address computation above the first test.
- `if (a && b) {both} else if (a) {one} else if (b) {other}` and the nested form with the positive test on the second flag: same layout, combined case falls through.

## Spelling that fixed it
Take the first parent with a conditional expression (`room ? Find(room) : &open`), keep the second as an initialised pointer overwritten under an `if`, and write the nested choice with the negated test first:
`if (useA) { if (!useB) { Add(a); } else { Begin(); Add(a); Add(b); End(); } } else if (useB) { Add(b); }`.
Read call targets as the image address minus the image base, never as the section-relative text in the listing comment.
