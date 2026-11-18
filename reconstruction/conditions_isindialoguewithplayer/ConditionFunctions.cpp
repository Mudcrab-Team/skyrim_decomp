// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// MenuTopicManager members and actor/form slots: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from public headers.
// names: GUESS(low); names, layouts and signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionFunctions, ConditionFunctions::IsInDialogueWithPlayer: GUESS(low); the static source container and original signature are unverified.
// 0x33bfc0 Condition::IsInDialogueWithPlayer
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
    // The editor ID lookup is a virtual call that may itself log; take the sink first so this line
    // is written to the sink that was active when the condition was evaluated.
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
