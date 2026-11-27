# 0x5bb750 ActiveEffect::ShouldUpdate

<!-- tags: construct/bitfield, construct/switch, method/diagnostic, method/sibling, sibling/fo4, wall/constant, wall/control-flow, wall/flag-fold, wall/layout, wall/register-schedule -->

- Function: 0x5bb750 ActiveEffect::ShouldUpdate
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: branch-layout
- Best score: 152/152 exact
- Attempts: 8

## What differed

A bool predicate that tests flag bits, a spell type and a few members, and returns "live" (the inverse of one
flag bit) from every early exit. Three things differed at once: every flag test needed the load, shift and test
shape, the first early exit was folded to a constant false while the target shares one exit that returns the
variable, and the set-membership test on the spell type came out as a shift or a compare chain where the target
has a constant mask in a register and a bit-test instruction behind a range check.

## Spellings tried that did not help

- Plain masks and `(flags >> n) & 1` on the member: memory tests, not the target's shift form (cookbook rule 16).
- A separate `if (!live) return live;` as the first guard: the compiler knows `live` is false there and returns a
  constant, so the shared exit is lost.
- `(1042 >> type) & 1`, `(mask & (1 << type))` and a `switch` over the three types: a shift, a shift-and-test
  and a chain of subtractions. A `_bittest` intrinsic on a local mask: the mask goes through memory.

## Spelling that fixed it

Rule 16's by-value bit helper for every flag, `!live || !spell` as one guard with one return, and the type set as
ORed equality tests on the enum, which this compiler turns into the range check plus a bit test on a constant mask.

```cpp
bool live = !TestBit(flags, 31);
if (!live || !spell) { return live; }
MagicSystem::SpellType type = spell->GetSpellType();
if (type != kDisease && type != kAbility && type != kAddiction) { return live; }
```
