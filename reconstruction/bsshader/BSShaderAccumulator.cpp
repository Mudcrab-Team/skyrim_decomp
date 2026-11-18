// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none.
// 0x14ecb90 BSShaderAccumulator::GetCurrentAccumulator
// 0x14ecba0 BSShaderAccumulator::SetCurrentAccumulator
// 0x1520d50 BSShaderAccumulator::StartGroupingAlphas
// 0x151ef00 BSShaderAccumulator::FinishAccumulatingPostResolveDepth
#include "BSShaderAccumulator.h"

// ms_currentAccumulator: GUESS(low); the global slot the accessors read and write
extern BSShaderAccumulator* ms_currentAccumulator;

// BuildAlphaGroups: GUESS(low); the callee receives the renderer, the bound, the list and the flag
BSBatchRenderer::GeometryGroup* BuildAlphaGroups(std::uint64_t a_renderer, NiBound* a_bound,
    std::uint64_t a_list, std::uint8_t a_flag);

BSShaderAccumulator* BSShaderAccumulator::GetCurrentAccumulator()
{
    return ms_currentAccumulator;
}

void BSShaderAccumulator::SetCurrentAccumulator(BSShaderAccumulator* a_accumulator)
{
    ms_currentAccumulator = a_accumulator;
}

BSBatchRenderer::GeometryGroup* BSShaderAccumulator::StartGroupingAlphas(NiBound* a_bound)
{
    return BuildAlphaGroups(unknown130, a_bound, unknown10, unknown51);
}

void BSShaderAccumulator::FinishAccumulatingPostResolveDepth(std::uint32_t flags)
{
    if (unknown150 == 0) {
        PrepareDepth();
    }
    NiAccumulator::FinishAccumulating();
}
