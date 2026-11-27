# 0x866b20 TESObjectREFR::sub_1407BAB40

<!-- tags: wall/control-flow -->

- Function: 0x866b20 TESObjectREFR::sub_1407BAB40
- Label: none
- Outcome: unsolved
- Cause: branch-layout
- Best score: 110/127 (aligned_matching_bytes)
- Attempts: 9

## What differed

Every honest signed range check on the signed 8-bit state field (`state < -1 || state > 6` or `state >= -1 && state <= 6`) compiles to the exact 127-byte size and emits the same sign-extend, increment, and compare against 7, but MSVC lowers the branch as `ja` with the in-range helper call falling through and the out-of-range `scale * 2.0f` path second. The target instead uses `jbe` with the out-of-range `scale * 2.0f` path falling through and the in-range helper call second. Rewriting the check as a `switch` over `-1..6` also narrows the state to an 8-bit `movzx` plus `inc al`/`cmp al, 7`/`ja`, shrinking the function to 126 bytes.

## Spellings tried that did not help

- `if (state < -1 || state > 6) { return scale * 2.0f; } return ConvertFloat(...) * scale;` (127/127 B size, 110/127 aligned bytes; `ja` instead of `jbe`)
- `if (state >= -1 && state <= 6) { return ConvertFloat(...) * scale; } return scale * 2.0f;` (127/127 B size, 110/127 aligned bytes; `ja` instead of `jbe`)
- `if (state > 6 || state < -1) { return scale * 2.0f; } return ConvertFloat(...) * scale;` (127/127 B size, 110/127 aligned bytes; `ja` instead of `jbe`)
- Shared `value * scale` return tail with `if (state < -1 || state > 6)` early return (127/127 B size; same `ja` branch order)
- `switch (other->state19D)` and `switch (static_cast<std::int32_t>(other->state19D))` with cases `-1..6` before or after `default` (126/127 B size, 94/127 aligned bytes; narrowed to 8-bit `movzx` and `ja`)

## Spelling that fixed it

none
