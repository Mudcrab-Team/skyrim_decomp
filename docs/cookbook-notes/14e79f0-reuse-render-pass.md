# 0x14e79f0 BSShaderProperty::RenderPassArray::ReinitOrAppendNew

<!-- tags: wall/register-schedule -->

- Function: 0x14e79f0 BSShaderProperty::RenderPassArray::ReinitOrAppendNew
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 98/123 aligned bytes
- Attempts: 5

## What differed

The null path that appends a new pass agreed. When reusing an existing pass, the candidate used the return register to transfer the geometry and technique arguments into the pass. The target kept that register available for the returned pass pointer earlier. The complete function sizes agreed.

## Spellings tried that did not help

Moving the geometry and technique assignments ahead of the shader assignments left the best score unchanged. Putting the existing-pass branch first changed the branch layout and reduced the score to 74/123. Restoring the null-first branch with a common return recovered 98/123. An inline reset method returning its receiver also reached 98/123.

## Spelling that fixed it

none
