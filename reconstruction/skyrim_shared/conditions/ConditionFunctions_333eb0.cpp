// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// TESObject and TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations in included header.
// TESObjectREFR data offset: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/T/TESObjectREFR.h.
// names: GUESS(low); names and signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionFunctions, ConditionFunctions::GetIsVoiceType: GUESS(low); the static source container and original signature are unverified.
// 0x333eb0 Condition::GetIsVoiceType
#include "ConditionFunctions_333eb0.h"
#include "../forms/TESBoundObject_333eb0.h"
struct BSHandleRefObject { void* vtable; unsigned int refCount, padding; };
struct BSAnimationEventSink { void* vtable; };
struct AnimationGraphManagerHolder { void* vtable; };
class TESObjectREFR : public TESForm, public BSHandleRefObject, public BSAnimationEventSink, public AnimationGraphManagerHolder {
public:
    TESBoundObject* baseObject;
};
extern TESObjectREFR* cachedVoiceReference;
extern BGSVoiceType* cachedVoice;
extern int FindVoiceInList(TESForm*, BGSVoiceType*);
extern void* conditionLogger;
extern const char voiceLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetIsVoiceType(TESObjectREFR* reference, TESForm* parameter, void*, double* result)
{
    *result = 0.0;
    if (reference) {
        BGSVoiceType* voice;
        if (reference == cachedVoiceReference) voice = cachedVoice;
        else {
            voice = reference->baseObject->GetObjectVoiceType();
            cachedVoice = voice;
            cachedVoiceReference = reference;
        }
        if (parameter) {
            if (parameter->formType != static_cast<FormType>(0x5b)) {
                if (parameter->formType == static_cast<FormType>(0x62) && reinterpret_cast<TESForm*>(voice) == parameter)
                    *result = 1.0;
            } else if (FindVoiceInList(parameter, voice) >= 0) {
                *result = 1.0;
            }
        }
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, voiceLogFormat, *result);
    return true;
}
