// Source exposure: binary-analysis.
// Code origin: original; pinned-image observations and labelled naming sources.
// SPDX-License-Identifier: CC0-1.0
// NiBoxBV, NiBoxBV::Copy: SYMBOLS(fo4-pdb)
// NiBoxBV::unk008, NiBoxBV::unk00C, NiBoxBV::unk010, NiBoxBV::unk014, NiBoxBV::unk018, NiBoxBV::unk01C, NiBoxBV::unk020, NiBoxBV::unk024, NiBoxBV::unk028, NiBoxBV::unk02C, NiBoxBV::unk030, NiBoxBV::unk034, NiBoxBV::unk038, NiBoxBV::unk03C, NiBoxBV::unk040: GUESS(low); copied scalar fields.
#pragma once
#include <cstddef>
class NiBoxBV
{
public:
    virtual ~NiBoxBV();
    void Copy(const NiBoxBV& source);
    float unk008;
    float unk00C;
    float unk010;
    float unk014;
    float unk018;
    float unk01C;
    float unk020;
    float unk024;
    float unk028;
    float unk02C;
    float unk030;
    float unk034;
    float unk038;
    float unk03C;
    float unk040;
};
static_assert(offsetof(NiBoxBV, unk008) == 8, "observed scalar prefix");
