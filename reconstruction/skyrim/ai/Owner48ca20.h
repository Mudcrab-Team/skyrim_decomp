// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code. Stamped as a twin of matched 0x48b9a0 (skyrim/ai/BGSProcedureTreeStackedExecState_48b910): source copied, names replaced by placeholders.
// Function48ca20, Owner48ca20: GUESS(low) STANDIN
// LoadGame, SaveGame, activeChild: GUESS(low) STANDIN
#pragma once
#include "BGSProcedureTreeStackedExecState_48b910.h"

class Owner48ca20 : public BGSProcedureTreeOneChildExecState
{
public:
    void SaveGame(BGSSaveGameBuffer& buffer);
    void LoadGame(BGSLoadGameBuffer& buffer);
    void Function48ca20();

private:
    std::uint32_t activeChild;
};

