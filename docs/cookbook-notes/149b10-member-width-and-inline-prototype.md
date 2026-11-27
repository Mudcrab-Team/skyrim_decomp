# 0x149b10 MapView::ClearAll

<!-- tags: method/sibling, sibling/f3, wall/layout -->

- Function: 0x149b10 MapView::ClearAll
- Label: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 25 of 25 same-shape functions pass the comparator after the two changes below
- Attempts: 2 (one UNBOUND, one pass)

## What differed
The sibling body compiled for x64 has the target's instruction count and opcodes. Two stores differ only by width: the sibling
clears and saves a pointer-sized member (`void*` in the 32-bit decompilation), the target a four-byte one. Twenty-five Skyrim
functions share this shape, so one rule closes all of them.

## Spellings tried that did not help
- Keeping the sibling's `void*` member: the stores stay eight bytes wide.
- Transplanting the in-class `inline void ClearAll();` as declared: the function is never emitted, because an inline member that
  nothing calls produces no code, and the comparator reports the function as UNBOUND rather than as a mismatch.

## Spelling that fixed it
Retype the member the fact points at (found by its displacement and by the name on the fact's source line) to the integer type of
the target width, and declare the cut-out member without `inline` so the out-of-line definition is emitted.

```cpp
struct MapView { /* ... */ unsigned int unk0C; void ClearAll(); };
void MapView::ClearAll() { /* loops unchanged */ unk0C = 0; }
```
