# 0x11cc8d0 CheckGoalReachedFunctor::Func1_1410BA7F0

<!-- tags: method/diagnostic -->

- Function: 0x11cc8d0 CheckGoalReachedFunctor::Func1_1410BA7F0
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: 92/92 (aligned_matching_bytes)
- Attempts: 4

## What differed

Three separate mismatches appeared: comparing `<` with an early `return false` loaded the member into a register instead of comparing the local against memory; casting a signed `int32_t` to `float` used packed integer conversion instead of scalar 64-bit conversion; and an inline `1.0f` literal targeted the wrong read-only constant.

## Spellings tried that did not help

- Early `if (context->unk40 < unk08) return false;` with `static_cast<std::int32_t>(context->unk20->unkA0) - 1`: inverted operand order on the float compare and used signed int-to-float conversion.
- Using `< 1.0f` on the final virtual call check: loaded the threshold into a register first instead of comparing the return register directly against memory.
- Using a `1.0f` literal with `>=`: matched all 92 code bytes but mismatched the referenced constant RVA.

## Spelling that fixed it

Guard with `if (context->unk40 >= unk08)`, keep `context->unk20->unkA0 - 1` unsigned (`uint32_t`) when converting to `float`, and compare the virtual call result with `>= kThreshold11cc8d0` declared as a `static const float` class constant.
