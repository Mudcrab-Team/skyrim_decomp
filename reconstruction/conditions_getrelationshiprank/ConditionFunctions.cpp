// Build: sse-steam-1-7-104; RVA 0x33b740; 148 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESObjectREFR::data and TESForm fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetRelationshipRank: GUESS(low); the static source container and original signature are unverified.
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
