# 0x98b0d0 UI3DSceneManager::SetCameraPosition

<!-- tags: construct/float, method/sibling, wall/register-schedule -->

- Function: 0x98b0d0 UI3DSceneManager::SetCameraPosition
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 56/62 aligned bytes; distance 0.5
- Attempts: 5

## What differed

The component-wise camera translation update and update call agree in size and operations. The remaining difference is the scheduling of initialization stores for the update-data time and flags. A local comparison has not passed.

## Spellings tried that did not help

Whole-point assignment produced a smaller function. Explicit component assignments reached the best score. A two-argument update-data constructor, reversed constructor assignments, and direct field assignments in both orders retained the scheduling difference. A one-worker permutation search scored 81 candidates without improving distance 0.5.

The body was adapted from the permitted anonymous game-code sibling at fo4-private@1b765c70, src/Game/Interface/UI3DSceneManager.cpp:61. Community declarations supplied the accessed layouts; target observations supplied the comparison evidence. Neither sibling shape nor community naming proves identity.

## Spelling that fixed it

none
