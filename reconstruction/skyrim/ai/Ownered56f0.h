// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup. Stamped as a twin of matched 0x465220 (skyrim/ai/BGSProcedureEat_465220): source copied, names replaced by placeholders.
// Ownered56f0: GUESS(low) STANDIN
// unknownProcedureData: GUESS(low) STANDIN
#pragma once
#include "BGSProcedureEat_465220.h"

class Ownered56f0 : public BGSProcedureBase
{
public:
    Ownered56f0();
    ~Ownered56f0() override;

private:
    std::uint8_t unknownProcedureData[0x30];
};
static_assert(sizeof(Ownered56f0) == 0x38, "observed allocation size");
