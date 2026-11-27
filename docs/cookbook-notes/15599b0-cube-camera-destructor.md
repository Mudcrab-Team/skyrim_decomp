# 0x15599b0 BSCubeMapCamera::~BSCubeMapCamera

<!-- tags: construct/destructor, wall/register-schedule -->

- Function: 0x15599b0 BSCubeMapCamera::~BSCubeMapCamera
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 160/160 aligned matching bytes
- Attempts: 4

## What differed

The provisional constructor name conflicts with three intrusive releases in reverse member order, followed by destruction of the scene array and camera base. The companion deleting entry uses that same sequence before conditional sized deletion.

## Spellings tried that did not help

Reading the smart-pointer member again after the atomic operation reloaded each pointer. A release member on the pointee removed those reloads. Its single-expression count test still gave different unwind information.

## Spelling that fixed it

Let member destructors perform the releases. In the pointee helper, keep the decremented count in a named local before testing it, as in cookbook rule 29. The compiler generated both the plain destructor here and the deleting entry at 0x155a2c0. Each first passed on comparison three.
