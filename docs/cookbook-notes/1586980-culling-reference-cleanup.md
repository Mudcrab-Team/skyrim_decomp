# 0x1586980 BSParabolicCullingProcess::~BSParabolicCullingProcess

<!-- tags: construct/destructor, wall/register-schedule -->

- Function: 0x1586980 BSParabolicCullingProcess::~BSParabolicCullingProcess
- Label: EXE_RTTI
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: local comparator PASS, 116/116 code bytes
- Attempts: 5

## What differed

The first draft reloaded each smart pointer after decrementing its reference count. It produced a 130-byte destructor for a 116-byte target.

## Spellings tried that did not help

Moving the decrement into a member function of the referenced object removed both reloads. Testing the atomic result directly still saved a register in the wrong stack slot, and the unwind check failed.

## Spelling that fixed it

Keep the release on the referenced object. In its release method, store the decremented count in a named local and test that local for zero, as in cookbook rule 29. The third scored comparison passed, and two subsequent comparisons confirmed the final declarations and comments.
