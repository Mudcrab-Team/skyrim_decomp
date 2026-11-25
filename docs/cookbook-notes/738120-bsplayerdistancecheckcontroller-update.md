# 0x738120 BSPlayerDistanceCheckController::Update

<!-- tags: abi/virtual, construct/bitfield, construct/float, construct/loop, method/diagnostic, method/sibling, sibling/fo4, wall/callee, wall/control-flow, wall/flag-fold, wall/inlining, wall/layout, wall/register-schedule -->

- Function: 0x738120 BSPlayerDistanceCheckController::Update
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 98.8 percent shape, 322 of 329 bytes
- Attempts: 13

## What differed

The whole body matches under the fast-float recipe (inline square root, same compare shapes, the same loop with a
clamped index) except the runtime cast of the controller's target to the scene-object type. The target walks the
type chain with no flag before the loop: the found path sets a bool to one, the exhausted and the null-type paths set
it to zero, and a conditional move on that bool picks the target pointer, which is then null-tested. The
candidate either threads the flag into jumps (no conditional move, shorter code) or sets the flag to false before
the walk, which moves one clear before the virtual call and keeps an extra callee-saved register.

## Spellings tried that did not help

- Helper with early `return true` / `return false`, called in a ternary, an if-assign or two levels of helpers: the flag folds into jumps.
- Flag set in the loop with `break`, rule 65's `if (matches) return object; return nullptr;`: the same threading.
- A flag recomputed each pass as `found = rtti == type`: keeps the conditional move, but the compare becomes a set-on-condition.
- `bool found = false;` before the walk (best, 98.8): the clear is hoisted above the null test of the type pointer.
- Result as `rtti ? cast : nullptr` after the walk; an uninitialised flag with an else branch; a null check first: all lower.
- The permuter (481 candidates): nothing better.

## Spelling that fixed it

none
