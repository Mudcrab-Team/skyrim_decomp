// BSTempEffectWeaponBlood: GUESS(low) STANDIN
/*
 * BSTempEffectWeaponBlood: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x4b6180 26 bytes.
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
// BSTempEffectWeaponBlood, BloodManager, bloodManager, BSTempEffectWeaponBlood::Function4b6180, BloodManager::Call784b20: GUESS(low) STANDIN
class BloodManager { public: void Call784b20(); };
extern BloodManager* bloodManager;
class BSTempEffectWeaponBlood { public: int Function4b6180(); };
