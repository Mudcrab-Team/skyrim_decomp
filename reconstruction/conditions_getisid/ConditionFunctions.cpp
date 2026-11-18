// Source exposure: mixed
// Origin: body structure adapted from the permitted FNV sibling cited below; declarations from public headers.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesconditionfunctions.cpp:1973
// TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declaration kit.
// TESObjectREFR and OBJ_REFR layout: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/T/TESObjectREFR.h.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions::GetIsID: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); body structure (clear result, bound-object test, one-entry reference cache with extra-data fallback, comparison, logging); another game's reconstruction, no evidence about this build
// cachedReference, cachedBase, GetExtraBase, LogCondition, conditionLogger, conditionLoggingEnabled: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); roles only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionFunctions, ConditionFunctions::GetIsID: GUESS(low); the static source container and original signature are unverified.
// 0x333dd0 Condition::GetIsID
#include "ConditionFunctions.h"
#include "TESForm.h"
class TESBoundObject;
struct NiPoint3 { float x, y, z; };
struct OBJ_REFR { TESBoundObject* objectReference; NiPoint3 angle, location; };
class BSExtraData;
struct ExtraDataList {
    virtual ~ExtraDataList();
    BSExtraData* data;
    void* presence;
    unsigned int lockThread, lockCount;
};
class BSHandleRefObject {
public:
    virtual ~BSHandleRefObject();
    volatile unsigned int refCount;
};
class AnimationEventSink {
public:
    virtual ~AnimationEventSink();
};
class AnimationGraphHolder {
public:
    virtual ~AnimationGraphHolder();
};
class TESObjectREFR : public TESForm, public BSHandleRefObject,
                      public AnimationEventSink, public AnimationGraphHolder {
public:
    OBJ_REFR data;
    void* parentCell;
    void* loadedData;
    ExtraDataList extraList;
    ExtraDataList* ExtraList() { return &extraList; }
};
extern TESObjectREFR* cachedReference;
extern TESBoundObject* cachedBase;
extern void* conditionLogger;
extern const char conditionLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern TESBoundObject* GetExtraBase(ExtraDataList*);
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetIsID(TESObjectREFR* reference, TESForm* parameter, void*, double* result)
{
    *result = 0.0;
    TESForm* form = nullptr;
    if (parameter && parameter->IsBoundObject()) form = parameter;
    if (reference && form) {
        TESBoundObject* base;
        if (reference == cachedReference) base = cachedBase;
        else {
            base = GetExtraBase(reference->ExtraList());
            if (!base) base = reference->data.objectReference;
            cachedReference = reference;
            cachedBase = base;
        }
        if (reinterpret_cast<TESForm*>(base) == form) *result = 1.0;
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, conditionLogFormat, *result);
    return true;
}
