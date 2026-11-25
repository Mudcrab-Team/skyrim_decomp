// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x14ecba0 (bsshader/BSShaderAccumulator): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// NiBound: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSBatchRenderer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSBatchRenderer::GeometryGroup: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); declared here only as a forward class
// Functionabfb40, Ownerabfb40, ms_currentAccumulator_abfb40: GUESS(low) STANDIN
// NiAlphaAccumulator, PrepareDepth, unknown130, unknown150, Function1520c90, Function15209f0, Function15213e0, Function1521150, Function1521170: GUESS(low) STANDIN
#pragma once
#include "BSShaderAccumulator.h"

class Ownerabfb40 : public NiAlphaAccumulator
{
public:
    static Ownerabfb40* GetCurrentAccumulator();
    static void Functionabfb40(Ownerabfb40* a_accumulator);
    virtual BSBatchRenderer::GeometryGroup* StartGroupingAlphas(NiBound* a_bound);
    virtual void FinishAccumulatingPostResolveDepth(std::uint32_t flags);

    void PrepareDepth();

    void Function1520c90(std::int32_t a_index);
    std::uint16_t Function15209f0();
    void Function15213e0(std::uint32_t a_flag);
    void Function1521150();
    static bool Function1521170(std::uint32_t a_value);

    // Members used by the compared bodies, split out of the padding; offsets are checked by the size assert.
    std::uint8_t unknown58[0xD8];  // 58
    std::uint64_t unknown130;      // 130
    std::uint8_t unknown138[0x18];  // 138
    std::uint32_t unknown150;      // 150
    std::uint8_t unknown154[0x2C];  // 154
};
static_assert(sizeof(Ownerabfb40) == 0x180, "Ownerabfb40 size");
