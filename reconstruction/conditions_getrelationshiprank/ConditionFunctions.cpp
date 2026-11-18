// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: independently reconstructed from target observations and public declarations.
// TESObjectREFR::data and TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetRelationshipRank: GUESS(low); the static source container and original signature are unverified.
// 0x33b740 Condition::GetRelationshipRank
#include "ConditionFunctions.h"
#include "../fo4b4c_686600/Actor.h"
extern int GetRelationshipIndex(TESBoundObject*, TESBoundObject*);
extern int relationshipValues[];
extern const char* relationshipNames[];
extern void* conditionLogger;
extern const char relationshipLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
// AsActor: GUESS(low); a form-type checked cast helper.
static inline TESObjectREFR* AsActor(TESObjectREFR* form)
{
    if (!form) return nullptr;
    return form->formType == 0x3e ? form : nullptr;
}
bool ConditionFunctions::GetRelationshipRank(TESObjectREFR* reference, TESObjectREFR* other, void*, double* result)
{
    TESObjectREFR* actor = AsActor(reference);
    if (actor && other) {
        int index = GetRelationshipIndex(actor->data.objectReference, other->data.objectReference);
        double value = relationshipValues[index];
        *result = value;
        if (conditionLoggingEnabled) LogCondition(conditionLogger, relationshipLogFormat, value, relationshipNames[index]);
    }
    return true;
}
