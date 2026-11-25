# 0x26ef60 TESFurniture::GetEntryPointFlags

<!-- tags: construct/loop, wall/control-flow, wall/flag-fold, sibling/fo4 -->

- Function: 0x26ef60 TESFurniture::GetEntryPointFlags
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: loop-shape
- Best score: 80/80 bytes, local comparator pass
- Attempts: 5

## What differed
The lookup keeps its zero-initialized payload separate from an initially false found flag. A key match sets both, so a matching zero payload still ends the search. Combining the payload with the loop's stopping condition changed behavior and the generated control flow. The permitted anonymous game-code sibling supplied this separation; its different build was a source lead, not match evidence.

## Spellings tried that did not help
An early return on a key match measured 4/80 matching bytes. Testing the payload in the loop condition reached 27/80 but could scan beyond a matching zero payload. An explicit empty-count exit followed by a do-while flag loop reached 9/80.

## Spelling that fixed it
Keep a payload result and a separate bool. Use a 32-bit index in `for (index = 0; index < count && !found; ++index)`, assign the payload and set found only inside the matching-key arm, then return the payload after the loop. This extends cookbook rule 35 to a payload whose zero value must not mean that no match was found. The local pass still requires independent verification and review.
