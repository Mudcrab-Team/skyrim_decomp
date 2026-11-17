// Build: sse-steam-1-7-104; RVA 0x33bfc0; 388 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// MenuTopicManager members and actor/form slots: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from public headers.
// names: GUESS(low); names, layouts and signatures are tentative.
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
// ConditionFunctions, ConditionFunctions::IsInDialogueWithPlayer: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
#include "Actor.h"
template<int N> struct DialogueEventSink { virtual ~DialogueEventSink(); };
struct DialogueCriticalSection { void* debugInfo; long lockCount, recursionCount; void* owningThread; void* semaphore; unsigned long long spinCount; };
struct RefHandle { unsigned int value; };
struct MenuTopicManager : DialogueEventSink<0>, DialogueEventSink<1>, DialogueEventSink<2> {
    void* selectedResponseNode;
    void* dialogueList;
    unsigned long long unknown28;
    void* rootTopicInfo;
    void* lastSelectedDialogue;
    DialogueCriticalSection criticalSection;
    RefHandle speaker;
};
extern MenuTopicManager* dialogueManager;
extern bool ActorIsInDialogue(TESObjectREFR*);
extern RefHandle* GetReferenceHandle(TESObjectREFR*, RefHandle*);
extern void* conditionLogger;
extern const char actorYesFormat[], actorNoFormat[], otherYesFormat[], otherNoFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
static void LogEditorID(TESObjectREFR* reference, const char* format)
{
    // log helper: the engine reads the logger pointer before resolving the name
    void* logger = conditionLogger;
    const char* name = reference->GetFormEditorID();
    LogCondition(logger, format, name);
}
bool ConditionFunctions::IsInDialogueWithPlayer(TESObjectREFR* reference, void*, void*, double* result)
{
    TESObjectREFR* actor = nullptr;
    *result = 0.0;
    actor = reference->formType == static_cast<FormType>(0x3e) ? reference : nullptr;
    if (actor) {
        if (ActorIsInDialogue(actor)) {
            *result = 1.0;
            if (conditionLoggingEnabled) LogEditorID(actor, actorYesFormat);
        } else if (conditionLoggingEnabled) LogEditorID(actor, actorNoFormat);
    } else if (reference->data.objectReference->formType == static_cast<FormType>(0x19)) {
        unsigned int speaker = dialogueManager->speaker.value;
        RefHandle handle;
        if (speaker == GetReferenceHandle(reference, &handle)->value) {
            *result = 1.0;
            if (conditionLoggingEnabled) LogEditorID(reference, otherYesFormat);
        } else if (conditionLoggingEnabled) LogEditorID(reference, otherNoFormat);
    }
    return true;
}
