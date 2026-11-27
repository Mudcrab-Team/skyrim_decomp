# 0xfb8770 NiPSysRotationModifier::LoadBinary_140D1FAD0

<!-- tags: method/diagnostic -->

- Function: 0xfb8770 NiPSysRotationModifier::LoadBinary_140D1FAD0
- Label: CRASHLOGGER_PDB(59818@2026.10.24), GUESS
- Outcome: fixed
- Cause: branch-layout
- Best score: 361/361 (aligned_matching_bytes)
- Attempts: 4

## What differed

Initializing the temporary byte variables to zero before reading them from the stream emitted two redundant zero stores. Keeping `randomAxis` and the axis stream read inside the file-version check also shifted the branch target and prevented stack-slot reuse for the subsequent stream call.

## Spellings tried that did not help

- Zero-initializing the temporary byte variables before calling `ReadValue`.
- Placing the `randomAxis` and `axis` loads inside the `fileVersion` branch.
- Naming the helper method `NiPoint3::LoadBinary`, which collided with an existing differently bound symbol entry.

## Spelling that fixed it

```cpp
if (a_stream.fileVersion >= 0x14000002u)
{
    ReadValue(a_stream.input, rotationSpeedVar);
    // ... the other version-gated reads, ending with the first flag
}
std::uint8_t axisFlag;
ReadValue(a_stream.input, axisFlag);
randomAxis = (axisFlag != 0);
axis.LoadFromStream(a_stream);
```
