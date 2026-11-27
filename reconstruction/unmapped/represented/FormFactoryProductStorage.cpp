// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and community declarations).
// Code origin: original factory method and allocation model. Adapted bodies: none.
// Factory and product identities: EXE_RTTI
// Allocation sizes and constructor calls: OBSERVED
// CreateImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Heap helpers, product storage and its constructor symbol: GUESS(low) STANDIN
// Product fields, component types and extents: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x149bc0 ConcreteFormFactory<EffectSetting,18>::CreateImpl
// CI hash: 0x149bc0 ?CreateImpl@?$ConcreteFormFactory@VEffectSetting@@$0BC@@@UEAAPEAVTESForm@@XZ
// 0x2697f0 ConcreteFormFactory<TESCombatStyle,80>::CreateImpl
// CI hash: 0x2697f0 ?CreateImpl@?$ConcreteFormFactory@VTESCombatStyle@@$0FA@@@UEAAPEAVTESForm@@XZ
// 0x27d5a0 ConcreteFormFactory<TESObjectARMO,26>::CreateImpl
// CI hash: 0x27d5a0 ?CreateImpl@?$ConcreteFormFactory@VTESObjectARMO@@$0BK@@@UEAAPEAVTESForm@@XZ
// 0x288670 ConcreteFormFactory<TESObjectWEAP,41>::CreateImpl
// CI hash: 0x288670 ?CreateImpl@?$ConcreteFormFactory@VTESObjectWEAP@@$0CJ@@@UEAAPEAVTESForm@@XZ
// 0x305db0 ConcreteFormFactory<TESWaterForm,84>::CreateImpl
// CI hash: 0x305db0 ?CreateImpl@?$ConcreteFormFactory@VTESWaterForm@@$0FE@@@UEAAPEAVTESForm@@XZ
// 0x307b90 ConcreteFormFactory<TESWeather,54>::CreateImpl
// CI hash: 0x307b90 ?CreateImpl@?$ConcreteFormFactory@VTESWeather@@$0DG@@@UEAAPEAVTESForm@@XZ
// 0x30abf0 ConcreteFormFactory<TESWorldSpace,71>::CreateImpl
// CI hash: 0x30abf0 ?CreateImpl@?$ConcreteFormFactory@VTESWorldSpace@@$0EH@@@UEAAPEAVTESForm@@XZ
// 0x31cb00 ConcreteFormFactory<BGSFootstepSet,111>::CreateImpl
// CI hash: 0x31cb00 ?CreateImpl@?$ConcreteFormFactory@VBGSFootstepSet@@$0GP@@@UEAAPEAVTESForm@@XZ
// 0x31dfb0 ConcreteFormFactory<BGSImpactDataSet,101>::CreateImpl
// CI hash: 0x31dfb0 ?CreateImpl@?$ConcreteFormFactory@VBGSImpactDataSet@@$0GF@@@UEAAPEAVTESForm@@XZ
// 0x32cce0 ConcreteFormFactory<BGSTextureSet,7>::CreateImpl
// CI hash: 0x32cce0 ?CreateImpl@?$ConcreteFormFactory@VBGSTextureSet@@$06@@UEAAPEAVTESForm@@XZ
// 0x341880 ConcreteFormFactory<Script,19>::CreateImpl
// CI hash: 0x341880 ?CreateImpl@?$ConcreteFormFactory@VScript@@$0BD@@@UEAAPEAVTESForm@@XZ
// 0x38afa0 ConcreteFormFactory<BGSBodyPartData,93>::CreateImpl
// CI hash: 0x38afa0 ?CreateImpl@?$ConcreteFormFactory@VBGSBodyPartData@@$0FN@@@UEAAPEAVTESForm@@XZ
// 0x39c7f0 ConcreteFormFactory<BGSRagdoll,106>::CreateImpl
// CI hash: 0x39c7f0 ?CreateImpl@?$ConcreteFormFactory@VBGSRagdoll@@$0GK@@@UEAAPEAVTESForm@@XZ
// 0x3bb570 ConcreteFormFactory<TESNPC,43>::CreateImpl
// CI hash: 0x3bb570 ?CreateImpl@?$ConcreteFormFactory@VTESNPC@@$0CL@@@UEAAPEAVTESForm@@XZ
// 0x3cdd40 ConcreteFormFactory<TESQuest,77>::CreateImpl
// CI hash: 0x3cdd40 ?CreateImpl@?$ConcreteFormFactory@VTESQuest@@$0EN@@@UEAAPEAVTESForm@@XZ
// 0x3e2e80 ConcreteFormFactory<TESRace,14>::CreateImpl
// CI hash: 0x3e2e80 ?CreateImpl@?$ConcreteFormFactory@VTESRace@@$0O@@@UEAAPEAVTESForm@@XZ
// CrashLogger flattens template arguments in its CreateImpl names. RTTI identifies the
// factory specializations below. For BGSFootstepSet it calls slot one vfunc_1 and gives an IMemoryHeap* return.
// The base and derived factories share this entry. The callee constructs BGSFootstepSet,
// whose primary base is TESForm.
#include "FormFactoryProductStorage.h"

// A throwing product constructor releases its allocation through global sized delete.
template<class T, unsigned char FormType>
TESForm* ConcreteFormFactory<T, FormType>::CreateImpl()
{
    // The bound constructor creates the real product. Its TESForm base shares this address.
    return reinterpret_cast<TESForm*>(new FormFactoryAllocation::FormFactoryProductStorage<T>);
}

template TESForm* ConcreteFormFactory<EffectSetting, 18>::CreateImpl();
template TESForm* ConcreteFormFactory<TESCombatStyle, 80>::CreateImpl();
template TESForm* ConcreteFormFactory<TESObjectARMO, 26>::CreateImpl();
template TESForm* ConcreteFormFactory<TESObjectWEAP, 41>::CreateImpl();
template TESForm* ConcreteFormFactory<TESWaterForm, 84>::CreateImpl();
template TESForm* ConcreteFormFactory<TESWeather, 54>::CreateImpl();
template TESForm* ConcreteFormFactory<TESWorldSpace, 71>::CreateImpl();
template TESForm* ConcreteFormFactory<BGSFootstepSet, 111>::CreateImpl();
template TESForm* ConcreteFormFactory<BGSImpactDataSet, 101>::CreateImpl();
template TESForm* ConcreteFormFactory<BGSTextureSet, 7>::CreateImpl();
template TESForm* ConcreteFormFactory<Script, 19>::CreateImpl();
template TESForm* ConcreteFormFactory<BGSBodyPartData, 93>::CreateImpl();
template TESForm* ConcreteFormFactory<BGSRagdoll, 106>::CreateImpl();
template TESForm* ConcreteFormFactory<TESNPC, 43>::CreateImpl();
template TESForm* ConcreteFormFactory<TESQuest, 77>::CreateImpl();
template TESForm* ConcreteFormFactory<TESRace, 14>::CreateImpl();
