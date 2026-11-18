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
#pragma once
// CharacterRelated, Character, Character::Related, Character::Forward2e87b0, CharacterRelated::Call22d840: GUESS(low) STANDIN
class CharacterRelated { public: void* Call22d840(); };
class Character { public: float Call8f1b50(); float Call8f1ad0(); float Forward8f21f0(); float Forward8f24c0(); float Forward8f25a0(); CharacterRelated* Related(); void* Forward2e87b0(); };

// Character::Call8f1b50, Character::Call8f1ad0, Character::Forward8f21f0, Character::Forward8f24c0, Character::Forward8f25a0: GUESS(low) STANDIN
// AdjustValue, limit21a, limit21b, limit24a, limit24b, limit25a, limit25b: GUESS(low) STANDIN
float AdjustValue(float, float, float);
extern float limit21a, limit21b, limit24a, limit24b, limit25a, limit25b;

