# 0xfb8900 NiPSysRotationModifier::SaveBinary_140D1FC60

<!-- tags: method/diagnostic -->

- Function: 0xfb8900 NiPSysRotationModifier::SaveBinary_140D1FC60
- Label: CRASHLOGGER_PDB(59818@2026.10.24), GUESS
- Outcome: fixed
- Cause: inlining
- Best score: 353/353 (aligned_matching_bytes)
- Attempts: 4

## What differed

Taking the address of a local byte variable inside `SaveBinary` prevented tail-call optimization on the final `axis.SaveBinary(a_stream)` call and shifted the stack offset of the stream helper's component size variable. Converting the boolean via a ternary conditional also emitted an extra comparison instead of a direct byte load.

## Spellings tried that did not help

- Declaring `std::uint8_t flag` directly in `SaveBinary` and passing it to `WriteValue`.
- Converting the boolean inside a `WriteBool` helper with `a_value ? 1 : 0`.
- Declaring `NiPoint3::SaveBinary` non-const, which collided with an existing differently bound symbol entry.

## Spelling that fixed it

```cpp
static void WriteBool(NiBinaryStream* a_binary, bool a_value)
{
    std::uint8_t byteValue = static_cast<std::uint8_t>(a_value);
    WriteValue(a_binary, byteValue);
}
```
