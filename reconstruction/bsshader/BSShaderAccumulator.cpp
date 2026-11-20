// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original bodies written from the local listing; declarations from the pinned community headers.
// Adapted bodies: none.
// 0x1520c90 BSShaderAccumulator::Function1520c90
// 0x15209f0 BSShaderAccumulator::Function15209f0
// 0x15213e0 BSShaderAccumulator::Function15213e0
// 0x1521150 BSShaderAccumulator::Function1521150
// 0x1521170 BSShaderAccumulator::Function1521170
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

// ProcessGroup, FlushGroups, ResetGroups: GUESS(low); the callees take the renderer or one of its groups
void ProcessGroup(void* a_group);
void FlushGroups(BatchRendererStandIn* a_renderer, std::uint64_t a_list, std::uint32_t a_flag);
void ResetGroups(BatchRendererStandIn* a_renderer, std::uint32_t a_flag);

void BSShaderAccumulator::Function1520c90(std::int32_t a_index)
{
    BatchRendererStandIn* renderer = reinterpret_cast<BatchRendererStandIn*>(unknown130);
    ProcessGroup(renderer->groups[a_index]);
}

std::uint16_t BSShaderAccumulator::Function15209f0()
{
    BatchRendererStandIn* renderer = reinterpret_cast<BatchRendererStandIn*>(unknown130);
    RenderPassGroup* group = *reinterpret_cast<RenderPassGroup**>(reinterpret_cast<std::uint8_t*>(renderer) + 0x98);
    return group->passCount;
}

void BSShaderAccumulator::Function15213e0(std::uint32_t a_flag)
{
    FlushGroups(reinterpret_cast<BatchRendererStandIn*>(unknown130), unknown10, a_flag);
}

void BSShaderAccumulator::Function1521150()
{
    ResetGroups(reinterpret_cast<BatchRendererStandIn*>(unknown130), 0);
}

bool BSShaderAccumulator::Function1521170(std::uint32_t a_value)
{
    return a_value - 0x5C000058u <= 3;
}
