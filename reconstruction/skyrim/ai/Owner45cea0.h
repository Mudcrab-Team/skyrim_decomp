// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the observed procedure cleanup. Stamped as a twin of matched 0x465220 (skyrim/ai/BGSProcedureEat_465220): source copied, names replaced by placeholders.
// Owner45cea0: GUESS(low) STANDIN
// unknownProcedureData: GUESS(low) STANDIN
#pragma once
#include "BGSProcedureEat_465220.h"

class Owner45cea0 : public BGSProcedureBase
{
public:
    Owner45cea0();
    ~Owner45cea0() override;

private:
    std::uint8_t unknownProcedureData[0x30];
};
static_assert(sizeof(Owner45cea0) == 0x38, "observed allocation size");
