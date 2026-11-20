// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x48b5f0 BGSProcedureTreeSequenceExecState::SaveGame
// 0x48b640 BGSProcedureTreeSequenceExecState::LoadGame
// 0x48b680 BGSProcedureTreeSequenceExecState::ForwardChildSlot08
#include "BGSProcedureTreeSequenceExecState_48b5f0.h"

void BGSProcedureTreeSequenceExecState::SaveGame(BGSSaveGameBuffer& buffer)
{
    BGSProcedureTreeOneChildExecState::SaveGame(buffer);
    buffer.SaveDataEndian(&activeChild, sizeof(activeChild), sizeof(activeChild), 0);
}

void BGSProcedureTreeSequenceExecState::LoadGame(BGSLoadGameBuffer& buffer)
{
    BGSProcedureTreeOneChildExecState::LoadGame(buffer);
    return buffer.LoadDataEndian(&activeChild, sizeof(activeChild), sizeof(activeChild));
}

void BGSProcedureTreeSequenceExecState::ForwardChildSlot08()
{
    if (child) {
        child->Slot08();
    }
}
