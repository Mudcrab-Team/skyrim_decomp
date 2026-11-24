# 0x7c66b0 DetectionState::Clear

<!-- tags: construct/allocation, construct/bitfield, construct/constructor, construct/float, method/binding, method/diagnostic, method/sibling, wall/constant, wall/flag-fold, wall/layout, wall/register-schedule -->

- Function: 0x7c66b0 DetectionState::Clear
- Label: COMMUNITY
- Outcome: unsolved
- Cause: register-allocation
- Best score: 100.0 sim, distance 3, 158/158 bytes, code-byte-mismatch (scratch float registers only)
- Attempts: 10

## What differed

A reset function that stores one float constant into three time-stamp members, a level and three flag bytes,
and copies a three-float zero constant into three point members. After the layout, the member-wise point copy
and one shared load of the constant, every instruction matches in order and size. The only difference is which
scratch float registers are used: the target keeps the time-stamp constant in the third register and starts the
point copies in the second, the candidate uses the first for the constant and starts the copies in the first.

## Spellings tried that did not help

- Immediate float constants (`-FLT_MAX` in the source): the compiler stores immediates, the target loads the
  constant from the read-only pool and stores it from a register.
- A default-constructed time-stamp temporary per statement (`unk18 = AITimeStamp();`): one load per store.
- The sibling's statement order (level and flags first, then stamps, then points): the stamp stores moved after
  the flag stores, further from the target.
- Making the shared stamp local non-const, and binding the zero constant to a local reference first: same bytes.
- The permuter (zero-form was the only mutation site): pool exhausted at once, nothing new compiled.

## Spelling that fixed it

none for the registers. What closed everything else, in plain C++:

```cpp
struct NiPoint3 {
    NiPoint3& operator=(const NiPoint3& a_rhs) { x = a_rhs.x; y = a_rhs.y; z = a_rhs.z; return *this; }
};
const AITimeStamp cleared;   // default constructor reads the shared constant once
unk18 = cleared;
unk28 = cleared;
unk38 = cleared;
```

A user-written member-wise assignment on the point type turns the twelve-byte copy into three scalar copies
(an implicit copy gives an eight-byte and a four-byte move). One named stamp object gives one load for three
stores where a temporary per statement gives three.
