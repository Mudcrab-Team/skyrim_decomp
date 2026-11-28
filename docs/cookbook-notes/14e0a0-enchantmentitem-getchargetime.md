# 0x14e0a0 EnchantmentItem::GetChargeTime

<!-- tags: method/diagnostic -->

- Function: 0x14e0a0 EnchantmentItem::GetChargeTime
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 345/347 (aligned_matching_bytes)
- Attempts: 4

## What differed

The auto-unrolled loop matches in length and shape. In the scalar remainder loop after the unrolled body, the effects array pointer is held in a different register.

## Spellings tried that did not help

- Declaring `float result = 0.0f;` at function entry and testing `if (IsAutoCalc())` around the loop closed the frame size and the saved registers; only the register of the remainder array pointer still differed.
- Hoisting `std::uint32_t count = effectCount;` and caching `Effect* effect = effects[i];`: produced identical code with the same register difference in the remainder loop.

## Spelling that fixed it

none
