# 0x30dad0 TESWorldSpace::GetClimate

<!-- tags: abi/calling-convention, construct/bitfield, construct/loop, method/diagnostic, method/sibling, sibling/fnv, wall/flag-fold, wall/inlining -->

- Function: 0x30dad0 TESWorldSpace::GetClimate
- Label: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
- Outcome: fixed
- Cause: inlining
- Best score: 48/54 aligned bytes in earlier rounds, 54/54 after the fix
- Attempts: 1 counted for GetClimate, 2 counted for the companion GetMapModel (0x30e140)

## What differed
The target tests the parent pointer and the use flag twice in a row (the same helper inlined at two
call sites) and then loops. Earlier sources used an iterative `while` over a helper that returned the
parent or null, and the compiler folded the two tests into one.

## Spellings tried that did not help
- An iterative `while (GetParentIfUsed(mask)) world = GetParentIfUsed(mask);` with a mask argument.
- For the companion function, a path local assigned in an `if` block with a mask-argument helper.

## Spelling that fixed it
Use the structure the Fallout New Vegas decompilation has for the same methods. A two-step helper:
`GetParentUseFlag(bit)` builds a mask from the bit index (`1u << bit`) and tests it, and
`GetParentWorld(bit)` is `if (parent && !GetParentUseFlag(bit)) return nullptr; return parent;`.
GetClimate is then the recursive early-return form
`if (GetParentWorld(4)) return GetParentWorld(4)->GetClimate(); return climate;`, which the compiler
turns into the loop. The companion GetMapModel (0x30e140) uses `GetParentWorld(2)` in a path local
guarded by an `if`, then falls back to its own model and a default string.

```cpp
TESWorldSpace* GetParentWorld(std::uint32_t f) { if (parentWorld && !GetParentUseFlag(f)) return nullptr; return parentWorld; }
TESClimate* GetClimate() { if (GetParentWorld(4)) return GetParentWorld(4)->GetClimate(); return climate; }
```
