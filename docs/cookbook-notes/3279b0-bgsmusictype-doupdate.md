# 0x3279b0 BGSMusicType::DoUpdate

<!-- tags: construct/bitfield, method/diagnostic, method/sibling, sibling/fo4, wall/flag-fold, wall/register-schedule -->

- Function: 0x3279b0 BGSMusicType::DoUpdate
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: instruction-order
- Best score: PASS (exact)
- Attempts: 5

## What differed

A status update on a music type: when the type has no tracks it is finished, when the current track has finished the type is either finished (and queued for removal when it plays once) or inactive, and a finishing type copies the track's status; then the track is updated. The same-named sibling body gave the whole structure. Two things were different from a straight copy. The flag test came out as a load into a register, a test of the low byte, and the flag set as an or on the register followed by a store, where the target tests the byte in memory and sets the bit with a memory or. And the block order was reversed: the target falls through into the "not play-once" arm.

## Spellings tried that did not help

- Flag word as a plain 32-bit member with `(flags & 1) != 0` and `flags |= 0x10`: load shared by the test and the or (93 percent, the first score).
- The same with the arms swapped so the not-play-once arm is the fall-through: fixed the block order only (+2.3), the register-held flag stayed.
- The two bits as bit-fields of the word: identical code to the plain word.

## Spelling that fixed it

Keep the arm order from the swap, and put the flag word in a small wrapper with `any(mask)` and `set(mask)` members, the way the community library's enumeration wrapper reads. The test then folds into a memory byte test and the set into a memory or, as in the target. (The same-name FO4 body had no hint of this: it wrote the plain operators.) The word is declared by value in the class, no extra storage.

```cpp
class MSTFlags
{
public:
    bool any(std::uint32_t a_mask) const { return (_impl & a_mask) != 0; }
    void set(std::uint32_t a_mask) { _impl |= a_mask; }
    std::uint32_t _impl;
};
...
if (!flags.any(kPlaysOnce)) { typeStatus = kInactive; } else { flags.set(kRemovalQueued); typeStatus = kFinished; }
```
