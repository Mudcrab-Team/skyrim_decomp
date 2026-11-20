// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// BGSProcedureTreeStackedExecState: EXE_RTTI
// ForwardChildSlot08, LoadGame, SaveGame, activeChild: GUESS(low)
#pragma once

#include "BGSProcedureTreeOneChildExecState_48b5f0.h"

class BGSProcedureTreeStackedExecState : public BGSProcedureTreeOneChildExecState
{
public:
    void SaveGame(BGSSaveGameBuffer& buffer);
    void LoadGame(BGSLoadGameBuffer& buffer);
    void ForwardChildSlot08();

private:
    std::uint32_t activeChild;
};
