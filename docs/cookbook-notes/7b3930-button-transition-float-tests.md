# 0x7b3930 RunHandler::ProcessButton

<!-- tags: construct/float, method/diagnostic -->

- Function: 0x7b3930 RunHandler::ProcessButton
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 13/43 aligned matching bytes
- Attempts: 4

## What differed

The original handler draft toggles the running flag on the observed button transitions. The first three native Windows comparisons produced a 58-byte candidate against the 43-byte target range. A fourth comparison using the documented `o2-fpfast` recipe produced a 38-byte candidate, still measuring 13/43 aligned matching bytes. The target's floating zero tests have fewer exceptional-value checks than the candidate. Cookbook rule 48 explained the extra exceptional-value checks; selecting its existing named recipe removed that part of the mismatch but did not close the remaining size and branch-shape difference. No recipe file or private task recipe input was edited. Source exposure is mixed: authorized observations of build sse-steam-1-7-104 and CommonLibSSE-NG declarations at b93280e (MIT); no sibling body was read or adapted.

## Spellings tried that did not help

Explicit equality and inequality against zero, direct floating-to-boolean conditions, and expressing the nonnegative duration condition as a negated negative test each measured 13/43. All four failed snapshots and reports remain private. The wall includes function size and branch structure, so it was not diagnosed as register allocation alone. Lesson retrieval returned no applicable indexed tags.

## Spelling that fixed it

None. The first three comparisons triggered the no-improvement stop. The parent then authorized one confirmation of the documented rule 48 recipe fix; it removed the exceptional-value checks but did not improve the score. The final draft retains the negated-negative duration condition and explicitly names `o2-fpfast`. Further work needs a source/branch-shape explanation rather than a register-only permutation. Drafted 2026-11-25 with the assigned gpt-6.1-sol workflow.
