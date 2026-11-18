// Origin: original reconstruction; Character class name from CommonLibSSE-NG include/RE/C/Character.h.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// CharacterRuntime: STANDIN GUESS(low)
// ForwardA, ForwardB, ForwardC, ForwardD, ForwardE, ForwardF, GetRuntime, ApplyA, ApplyB, ApplyC, ApplyD, ApplyE, ApplyF: GUESS(low)
// 0x6a6920 Character::ForwardA
// 0x6a6960 Character::ForwardB
// 0x6a6c90 Character::ForwardC
// 0x6a5b00 Character::ForwardD
// 0x6a5bc0 Character::ForwardE
// 0x6a7020 Character::ForwardF
#include "Character.h"
void Character::ForwardA() { GetRuntime()->ApplyA(); }
void Character::ForwardB() { GetRuntime()->ApplyB(); }
void Character::ForwardC() { GetRuntime()->ApplyC(); }
void Character::ForwardD(void* value) { GetRuntime()->ApplyD(value); }
void Character::ForwardE(void* value) { GetRuntime()->ApplyE(value); }
void Character::ForwardF(void* value) { GetRuntime()->ApplyF(value); }
