# 0x1587620 BSShadowFrustumLight::BSShadowFrustumLight

<!-- tags: construct/constructor, wall/register-schedule -->

- Function: 0x1587620 BSShadowFrustumLight::BSShadowFrustumLight
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: 833/833
- Attempts: 3

## What differed

The constructor clamps two half angles with a minimum and a maximum. The target takes the float constants as memory operands of the minimum and maximum instructions with the angle register as the destination. A first draft that reassigned the same variable on each clamp step compiled to a compare and a branch for the minimum, and a second spelling with the constant first loaded the constant into a register.

## Spellings tried that did not help

Reassigning one variable on each clamp step with a conditional expression gave compare and branch. The same with plain if statements loaded the constant into a register first. Named extern constants instead of literals always loaded the constant into a register. A fast-float recipe changed which registers hold the parameters without helping.

## Spelling that fixed it

Give each clamp step its own local variable and use literals: `float raw = fov * 0.5f; float capped = raw < high ? raw : high; float half = capped > low ? capped : low;`. This produced the memory-operand minimum and maximum and matched the whole constructor.
