// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xf5d860 NiMultiTargetTransformController::SaveBinary
// 0xf5d900 NiMultiTargetTransformController::IsEqual
#include "NiMultiTargetTransformController_f5d860.h"

// RVA 0xf5d860, 147 bytes: save the base state, write the interpolator count, then one
// reference per entry.
void NiMultiTargetTransformController::SaveBinary(NiStream& a_stream)
{
    BaseSaveBinary(a_stream);

    NiStreamBuffer* buffer = a_stream.outBuffer;
    std::uint32_t writeSize = 2;
    buffer->transferred += buffer->writeFn(buffer, &m_count, 2, &writeSize, 1);

    for (std::uint16_t i = 0; i < m_count; ++i) {
        a_stream.WriteRef(m_entryPtrs[i]);
    }
}

// RVA 0xf5d900, 151 bytes: equal when the base matches and every entry slot is either empty
// on both sides or holds entries that compare equal.
bool NiMultiTargetTransformController::IsEqual(NiObject* a_object)
{
    if (!BaseIsEqual(a_object)) {
        return false;
    }

    NiMultiTargetTransformController* other = static_cast<NiMultiTargetTransformController*>(a_object);
    if (other->m_count != m_count) {
        return false;
    }

    for (std::uint16_t i = 0; i < m_count; ++i) {
        ControlledEntry* mine = m_entryPtrs[i];
        ControlledEntry* theirs = other->m_entryPtrs[i];
        if (mine) {
            if (!theirs || !theirs->IsEqualEntry(mine)) {
                return false;
            }
        } else if (theirs) {
            return false;
        }
    }
    return true;
}
