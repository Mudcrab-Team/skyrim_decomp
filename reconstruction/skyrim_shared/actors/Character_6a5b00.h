// Origin: original reconstruction; Character class name from CommonLibSSE-NG include/RE/C/Character.h.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// CharacterRuntime: STANDIN GUESS(low)
// ForwardA, ForwardB, ForwardC, ForwardD, ForwardE, ForwardF, GetRuntime, ApplyA, ApplyB, ApplyC, ApplyD, ApplyE, ApplyF: GUESS(low)
#pragma once
class CharacterRuntime { public:
 void ApplyA();
 void ApplyB();
 void ApplyC();
 void ApplyD(void* value);
 void ApplyE(void* value);
 void ApplyF(void* value);
 };
class Character { public:
 CharacterRuntime* GetRuntime();
 void ForwardA();
 void ForwardB();
 void ForwardC();
 void ForwardD(void* value);
 void ForwardE(void* value);
 void ForwardF(void* value);
 };
