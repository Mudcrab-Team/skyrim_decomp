# 0x15f5880 UI_image::Function15f5880

<!-- tags: construct/float, wall/control-flow, method/diagnostic -->

- Function: 0x15f5880 UI_image::Function15f5880
- Label: GUESS(low)
- Outcome: fixed
- Cause: float-codegen
- Best score: PASS; 49/49 exact code bytes
- Attempts: 3 (two drafting comparisons and one final declaration-label comparison)

## What differed
The first handwritten point query compiled to 57 bytes against a 49-byte target, with two additional instructions. Ordinary less-than lower-bound checks do not reject unordered float values. The observed lower-bound checks do, while the upper-bound checks test strictly greater-than. The original owner and descriptive field names remain uncorroborated; the unit explicitly labels its partial declarations as stand-ins.

## Spellings tried that did not help
Using less-than for both lower-bound failures left the larger function. Tagged float and control-flow lesson retrieval supplied general leads but did not identify this predicate difference.

## Spelling that fixed it
Retain the upper-bound greater-than failures and express each lower-bound failure as the negation of greater-than-or-equal. This preserves rejection of unordered coordinates and matches under the default precise-float recipe. The successful path writes the selected object and its observed result value. The second local comparison passed; the third confirmed the final declaration labels and source digest. This is a candidate, not acceptance.
