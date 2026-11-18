/*
 * PlayerCharacter: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x761440 28 bytes; RVA 0x758450 29 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Function ownership and method signatures remain unverified; class declarations are stand-ins.
 * Types adapted from CharmedBaryon/CommonLibSSE-NG at b93280e832f263dbef44e44cbe2936622a02f91a (MIT); see header notice.
 */
// PlayerCharacter: STANDIN EXE_RTTI
// ModifyAnimationUpdateData, UnlockWord, BSAnimationUpdateData, deltaTime, pad04, unkFunctionPtr, refr, optionalEyePosition, updateFunctor, flags, unk2A, unk2B, unk2C, unk2D, unk2E, unk2F, TESWordOfPower: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// UpdateBase, UnlockBase, SetKnown, NiPoint3, IPostAnimationChannelUpdateFunctor, TESObjectREFR: GUESS(low)
#include "PlayerCharacter_758450.h"

void PlayerCharacter::ModifyAnimationUpdateData(BSAnimationUpdateData& data) { UpdateBase(data); data.optionalEyePosition = nullptr; }
void PlayerCharacter::UnlockWord(TESWordOfPower* power) { UnlockBase(power); power->SetKnown(true); }
