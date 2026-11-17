// Build: sse-steam-1-7-104; RVA 0x333eb0; 211 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESObject and TESBoundObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations in included header.
// TESObjectREFR data offset: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/T/TESObjectREFR.h.
// names: GUESS(low); names and signatures are tentative.
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// ConditionFunctions, ConditionFunctions::GetIsVoiceType: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
#include "TESBoundObject.h"
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
