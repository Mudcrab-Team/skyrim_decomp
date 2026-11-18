// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xf5de10 NiMultiTargetTransformController::GetInterpolatorCount
// 0xf5de20 NiMultiTargetTransformController::GetInterpolatorID
// 0xf5b520 NiMultiTargetTransformController::~NiMultiTargetTransformController
// 0xf5e280 NiMultiTargetTransformController::GuaranteeTimeRange
// 0xf5de40 NiMultiTargetTransformController::GetInterpolatorIndex
// 0xf5d7a0 NiMultiTargetTransformController::LoadBinary
// 0xf5d860 NiMultiTargetTransformController::SaveBinary
// 0xf5d900 NiMultiTargetTransformController::IsEqual
// 0xf5df30 NiMultiTargetTransformController::ResetTimeExtrema
// 0xf5e350 NiMultiTargetTransformController::ProcessClone
#include "NiMultiTargetTransformController.h"


// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiMultiTargetTransformController::NiMultiTargetTransformController()
{
}

// RVA 0xf5de10, 5 bytes
std::uint16_t NiMultiTargetTransformController::GetInterpolatorCount() const
{
    return m_count;
}

// RVA 0xf5de20, 16 bytes
const char* NiMultiTargetTransformController::GetInterpolatorID(std::uint16_t a_index)
{
    return m_entryPtrs[a_index]->name;
}

// RVA 0xf5e280, 108 bytes: every entry is told the same time range.
void NiMultiTargetTransformController::GuaranteeTimeRange(float a_startTime, float a_endTime)
{
    for (std::uint16_t i = 0; i < m_count; ++i) {
        m_entries[i].GuaranteeTimeRange(a_startTime, a_endTime);
    }
}
