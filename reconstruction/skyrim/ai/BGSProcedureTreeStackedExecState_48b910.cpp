// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x48b910 BGSProcedureTreeStackedExecState::SaveGame
// 0x48b960 BGSProcedureTreeStackedExecState::LoadGame
// 0x48b9a0 BGSProcedureTreeStackedExecState::ForwardChildSlot08
#include "BGSProcedureTreeStackedExecState_48b910.h"

void BGSProcedureTreeStackedExecState::SaveGame(BGSSaveGameBuffer& buffer)
{
    BGSProcedureTreeOneChildExecState::SaveGame(buffer);
    buffer.SaveDataEndian(&activeChild, sizeof(activeChild), sizeof(activeChild), 0);
}

void BGSProcedureTreeStackedExecState::LoadGame(BGSLoadGameBuffer& buffer)
{
    BGSProcedureTreeOneChildExecState::LoadGame(buffer);
    return buffer.LoadDataEndian(&activeChild, sizeof(activeChild), sizeof(activeChild));
}

void BGSProcedureTreeStackedExecState::ForwardChildSlot08()
{
    if (child) {
        child->Slot08();
    }
}
