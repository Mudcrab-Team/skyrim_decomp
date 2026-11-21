// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of the stair agent's actor lookup.
// 0x7a6760 MovementHandlerAgentStairsHelper::RefreshActor
#include "MovementHandlerAgentStairsHelper_7a6760.h"

void MovementHandlerAgentStairsHelper::RefreshActor()
{
    const auto formID = owner->vtable->GetActorFormID(owner);
    auto* form = TESForm::LookupByID(formID);
    if (form && form->formType == FormType::ActorCharacter) {
        actor = form;
    } else {
        actor = nullptr;
    }
}
