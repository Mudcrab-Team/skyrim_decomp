# 0x7b3930 RunHandler::ProcessButton

<!-- tags: construct/float, method/diagnostic -->

- Function: 0x7b3930 RunHandler::ProcessButton
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: float-codegen
- Best score: distance 9 (from 14) with the o2-fpfast recipe named in the unit; not a byte match
- Attempts: 5 counted comparisons in total

## What differed

The original handler draft toggles the running flag on the observed button transitions. The first three native Windows comparisons produced a 58-byte candidate against the 43-byte target range. A fourth comparison using the documented `o2-fpfast` recipe produced a 38-byte candidate, still measuring 13/43 aligned matching bytes. The target's floating zero tests have fewer exceptional-value checks than the candidate. Cookbook rule 48 explained the extra exceptional-value checks; selecting its existing named recipe removed that part of the mismatch but did not close the remaining size and branch-shape difference. No recipe file or private task recipe input was edited. Source exposure is mixed: authorized observations of build sse-steam-1-7-104 and CommonLibSSE-NG declarations at b93280e (MIT); no sibling body was read or adapted.

## Spellings tried that did not help

Explicit equality and inequality against zero, direct floating-to-boolean conditions, and expressing the nonnegative duration condition as a negated negative test each measured 13/43. All four failed snapshots and reports remain private. The wall includes function size and branch structure, so it was not diagnosed as register allocation alone. Lesson retrieval returned no applicable indexed tags.

- Naming the o2-fpfast recipe in the unit header (cookbook rule 48) removed the parity branches and took the distance from 14 to 9. Reversed comparison operands, and two sequential guarded statements with an early return, did not move it (9 and 9.5).
- What is left: the target tests the held-down value twice (once on each side of the value test) while the compiler folds both tests and emits a shorter body (38 against 43 bytes).

## Spelling that fixed it
None. The unit now names the fast-float recipe.
