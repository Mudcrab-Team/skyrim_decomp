# 0x2f3d30 TESObjectREFR sub_2f3d30

- Function: 0x2f3d30 TESObjectREFR sub_2f3d30
- Label: none (unit not published; name is a guess)
- Outcome: fixed
- Cause: branch-layout
- Best score: matched at attempt 2
- Attempts: 2

## What differed

A select between two pointers (the space, else the cell). The null-check-first ternary produces the branch layout the target has; the other two spellings gave a different jump shape.

## Spellings tried that did not help

space ? space : cell, and an if-assign form.

## Spelling that fixed it

```cpp
return space == nullptr ? cell : space;
```
