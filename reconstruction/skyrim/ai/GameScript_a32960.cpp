// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: fnv_00982310::GameScript::CleanupAllBindings.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout/ai/combatcontroller.cpp:658
// 0xa32960 fnv_00982310::GameScript::CleanupAllBindings
// CI hash: 0xa32960 ?CleanupAllBindings@GameScript@fnv_00982310@@QEAAXPEAUBGSLoadFormBuffer@2@@Z
#include "GameScript_a32960.h"

namespace fnv_00982310 {
void GameScript::CleanupAllBindings(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((TESNPC*)this)->Revert(apLoadGameBuffer);
    this->Func0097f390();
    this->UpdatePointer();
    this->Func0097d9d0();
    this->UpdateActorValues();
}
}
