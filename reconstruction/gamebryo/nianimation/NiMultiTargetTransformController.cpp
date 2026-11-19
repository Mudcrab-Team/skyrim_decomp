// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
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
#include <cstring>


// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiMultiTargetTransformController::NiMultiTargetTransformController()
{
}

// RVA 0xf5d7a0, 147 bytes: load the base state, read the interpolator count from the stream,
// size the entry arrays and then load one entry per slot.
void NiMultiTargetTransformController::LoadBinary(NiStream& a_stream)
{
    BaseLoadBinary(a_stream);

    NiStreamBuffer* buffer = a_stream.inBuffer;
    std::uint32_t readSize = 2;
    buffer->transferred += buffer->readFn(buffer, &m_count, 2, &readSize, 1);

    AllocateEntries(m_count);

    for (std::uint16_t i = 0; i < m_count; ++i) {
        m_entryPtrs[i] = LoadEntry(&a_stream);
    }
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

// RVA 0xf5de40, 120 bytes: the index of the first entry whose name matches a_id, else the
// missing default.
std::uint16_t NiMultiTargetTransformController::GetInterpolatorIndex(const char* a_id) const
{
    if (a_id) {
        for (std::uint16_t i = 0; i < m_count; ++i) {
            ControlledEntry* entry = m_entryPtrs[i];
            if (entry && std::strcmp(entry->name, a_id) == 0) {
                return i;
            }
        }
    }
    return g_missingInterpolatorIndex;
}
