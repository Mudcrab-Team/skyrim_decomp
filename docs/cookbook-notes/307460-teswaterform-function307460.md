# 0x307460 TESWaterForm::Function307460

<!-- tags: wall/register-schedule, construct/vector -->

- Function: 0x307460 TESWaterForm::Function307460
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 768/865 (aligned_matching_bytes)
- Attempts: 6

## What differed

Using `UnpackColor(unk100, 1.0f)` reached the exact 865-byte size and reproduced all instructions except two regions: for `reflectionColor`, the target initializes the stack temporary's alpha lane with an immediate `1.0f` store and packs RGB with three shuffles, whereas the candidate loads `1.0f` from `.rdata` and uses four shuffles; and for `aboveWaterFogAmount * kFlowScale`, the candidate loads `kFlowScale` before the member because `kFlowScale` is an `extern const float` rather than a compile-time literal.

## Spellings tried that did not help

- Calling `UnpackColor(unk100, 1.0f)` reached 865/865 bytes (`768/865` aligned) but kept the `.rdata` load and four shuffles for `reflectionColor`.
- Adding a one-argument `UnpackColor(std::uint32_t)` overload or a local `NiColorA` helper with `out.a = 1.0f` first produced identical code (`768/865`).
- Assigning `refl.a = 1.0f` before the RGB fields in an inline block emitted the three-shuffle form, but broadcast `1.0f` from `.rdata` instead of storing immediate `1.0f` to the stack slot (`762/865`, 864 B).
- Using `float flow = unk154; flow *= kFlowScale;` kept `kFlowScale` loaded first.

## Spelling that fixed it

none
