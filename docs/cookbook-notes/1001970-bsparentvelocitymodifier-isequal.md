# 0x1001970 BSParentVelocityModifier::IsEqual

<!-- tags: construct/float, wall/control-flow -->

- Function: 0x1001970 BSParentVelocityModifier::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: branch-layout
- Best score: 62/62 (aligned_matching_bytes)
- Attempts: 4

## What differed

Two differences occurred. First, under `o2-fpfast`, writing `damping == other->damping` loaded `other->damping` into `xmm0` and compared against `this->damping`, whereas the target loaded `this->damping` first; reversing the operands to `other->damping == damping` reproduced the register load. Second, an early `return false` placed the register restore before clearing the return register, whereas storing the base result in a `bool` variable and updating it inside `if (equal)` let the false branch skip clearing `al` and jump directly to the epilogue restore.

## Spellings tried that did not help

- `if (!NiPSysModifier::IsEqual(a_other)) return false; return damping == other->damping;`: reversed `ucomiss` operand order and placed register restore before clearing `al`.
- `if (!NiPSysModifier::IsEqual(a_other)) return false; return other->damping == damping;`: fixed `ucomiss` operands, but still jumped to the restore-then-clear sequence.
- `if (NiPSysModifier::IsEqual(a_other)) { return other->damping == damping; } return false;`: identical branch layout to the early-return form.

## Spelling that fixed it

```cpp
bool equal = NiPSysModifier::IsEqual(a_other);
if (equal) {
    auto* other = static_cast<BSParentVelocityModifier*>(a_other);
    equal = (other->damping == damping);
}
return equal;
```
