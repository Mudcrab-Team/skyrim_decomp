// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSProcedureDialogueActivate.cpp:11
// 0x462a20 BGSProcedureDialogueActivate::InitActorLocation
// Adapted bodies: BGSProcedureDialogueActivate::InitActorLocation from the sibling source named above
#include "BGSProcedureDialogueActivate_462a20.h"

void BGSProcedureDialogueActivate::InitActorLocation(BGSProcessContext& a_context, BGSVisitProceduresInitActorLocation& a_visitor) const
{
    ExecStateHolder* state = a_context.execState;
    if (!state->location)
        InitExecState(a_context);
    const IAIWorldLocation* location = state->location;
    if (location)
        a_visitor.SetInitialLocation(location);
}
