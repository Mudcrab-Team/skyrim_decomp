// Character: GUESS(low) STANDIN
/*
 * Character: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x2e87b0 31 bytes; RVA 0x8f21f0 34 bytes; RVA 0x8f24c0 34 bytes; RVA 0x8f25a0 34 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * No external body or declaration has yet been adapted. Stand-ins are unverified.
 */
#include "Character_2e87b0.h"
void* Character::Forward2e87b0() { auto* related = Related(); return related ? related->Call22d840() : nullptr; }
float Character::Forward8f21f0() { return AdjustValue(Call8f1b50(), limit21a, limit21b); }
float Character::Forward8f24c0() { return AdjustValue(Call8f1ad0(), limit24a, limit24b); }
float Character::Forward8f25a0() { return AdjustValue(Call8f1ad0(), limit25a, limit25b); }

