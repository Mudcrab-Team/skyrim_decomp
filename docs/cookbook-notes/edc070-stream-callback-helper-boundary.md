# 0xedc070 three-component stream transfer

<!-- tags: abi/calling-convention, construct/serialization, method/sibling, wall/callee, wall/register-schedule -->

- Function: 0xedc070 three-component stream transfer
- Label: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
- Outcome: fixed
- Cause: inlining
- Best score: PC comparator pass, 177-byte extent including unwind
- Attempts: 3

## What differed
The stream stores read and write callbacks directly. Treating it as an object whose first member points to a separate callback table added a load at every transfer. Flattening the corrected callback calls then left the repeated component-size store in a different order.

## Spellings tried that did not help
A separately pointed callback table; direct expanded callback calls with a fresh size local at every component.

## Spelling that fixed it
Use the sibling stream Read or Write helper, whose local component size is four, and call it separately for the three scalar components. Both the input entry at 0xedbfb0 and output entry at 0xedc070 passed on the PC. The permitted sibling bodies and declarations are cited in the units; the sibling shape itself is only a lead.
