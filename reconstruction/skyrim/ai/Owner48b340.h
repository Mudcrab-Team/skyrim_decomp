// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code. Stamped as a twin of matched 0x48b9a0 (skyrim/ai/BGSProcedureTreeStackedExecState_48b910): source copied, names replaced by placeholders.
// Function48b340, Owner48b340: GUESS(low) STANDIN
// LoadGame, SaveGame, activeChild: GUESS(low) STANDIN
#pragma once
#include "BGSProcedureTreeStackedExecState_48b910.h"

class Owner48b340 : public BGSProcedureTreeOneChildExecState
{
public:
    void SaveGame(BGSSaveGameBuffer& buffer);
    void LoadGame(BGSLoadGameBuffer& buffer);
    void Function48b340();

private:
    std::uint32_t activeChild;
};

