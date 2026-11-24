# 0x153b250 BSShaderTextureSet::SaveBinary

- Function: 0x153b250 BSShaderTextureSet::SaveBinary
- Label: none
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 116/116, unwind covered
- Attempts: 1 (earlier drafters failed on the home-slot layout)

## What differed
The saved callee-saved register sat in the wrong home slot, and the two serialization locals (the
component size and the count) did not land in the second and third home slots.

## Spellings tried that did not help
Bundling both locals inside one custom write helper (the earlier source did this).

## Spelling that fixed it
Write through the stream's own `write` plus a small `binary_write` helper, and declare the count in
the caller as a named `std::uint32_t count = 9`. The saved register then takes the first slot and the
two locals take the next two.
