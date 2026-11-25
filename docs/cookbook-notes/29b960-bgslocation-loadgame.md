# 0x29b960 BGSLocation::LoadGame

<!-- tags: abi/calling-convention, construct/allocation, construct/loop, construct/serialization, method/diagnostic, wall/constant, wall/control-flow, wall/layout, wall/register-schedule -->

- Function: 0x29b960 BGSLocation::LoadGame
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: loop-shape
- Best score: sim 93.3 (Sonnet; not a byte match)
- Attempts: 7

## What differed
Near-pilot function (483 bytes), Sonnet draft 77.0 at the first score and 93.3 at the end (not a byte match). The first draft took
the thread-local save and restore guard from cookbook rule 21 and an array resize helper. The final read loop counts the element
count down while indexing by offset; the draft used one counter. The buffer read call takes the size twice (three parameters in the
community header; the decompiler showed two).

## Spellings tried that did not help
- Opening the community header of the buffer class after the listing: the third parameter was missed for four rounds.
- A register-only residue in the fill loop, the comparison operand order and a constant in the thread-local access: left; they look
  like permuter work.

## Spelling that fixed it
A separate 64-bit down-counter plus an index in the final read loop (77.9 to 91.7, +13.8, the largest gain for the smallest edit);
flipping the grow and shrink branches and the version test (+0.9); a 64-bit zero-fill counter behind a non-empty guard (+0.4); the
third parameter of the buffer read (+1.2). Note that an allocation failure falls into the read loop in the target as well: keep that
behaviour, do not guard it away.

The snippet is a generic shape with invented names, not the unit's code.

```cpp
for (std::uint64_t remaining = count; remaining != 0; --remaining, offset += stride) {
    ReadElement(offset);
}
```
