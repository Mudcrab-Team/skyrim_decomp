// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xffd880 BSProceduralLightningController::GetInterpolator
// 0xffd7d0 BSProceduralLightningController::GetInterpolatorID
// 0xffc810 BSProceduralLightningController::LoadBinary
// 0xffe540 BSProceduralLightningController::InterpolatorIsCorrectType
// 0xffc920 BSProceduralLightningController::RegisterStreamables
// 0xffca50 BSProceduralLightningController::IsEqual
#include "BSProceduralLightningController.h"

// RVA 0xffd880, 12 bytes.
NiInterpolator* BSProceduralLightningController::CreatePoseInterpolator(std::uint16_t)
{
    return nullptr;
}

void BSProceduralLightningController::SynchronizePoseInterpolator(NiInterpolator*, std::uint16_t)
{
}

void BSProceduralLightningController::GuaranteeTimeRange(float, float)
{
}

NiInterpolator* BSProceduralLightningController::GetInterpolator(std::uint16_t a_index) const
{
    return interpolators[a_index];
}

// RVA 0xffd7d0, 24 bytes.
const char* BSProceduralLightningController::GetInterpolatorID(std::uint16_t a_index)
{
    if (a_index < 9) {
        return g_procLightningIDNames[a_index];
    }
    return nullptr;
}

// RVA 0xffc810, 99 bytes.
void BSProceduralLightningController::LoadBinary(NiStream& a_stream)
{
    NiTimeController_LoadBinary(this, a_stream);
    for (std::size_t i = 9; i != 0; --i) {
        StreamReadSlot(a_stream);
    }
    ReadStreamSubA(subA, a_stream);
    ReadStreamSubB(subB, a_stream);
    StreamReadSlot(a_stream);
}

// RVA 0xffe540, 113 bytes.
bool BSProceduralLightningController::InterpolatorIsCorrectType(NiInterpolator* a_interpolator, std::uint16_t a_index) const
{
    if (a_index > 1) {
        if (a_index > 8 || a_interpolator == nullptr) {
            return false;
        }
        for (const NiRTTI* rtti = a_interpolator->GetRTTI(); rtti != nullptr; rtti = rtti->parent) {
            if (rtti == &NiRTTI_NiFloatInterpolator) {
                return true;
            }
        }
        return false;
    }
    if (a_interpolator == nullptr) {
        return false;
    }
    return a_interpolator->GetRTTI() == &NiRTTI_NiBoolTimelineInterpolator;
}

// RVA 0xffc920, 142 bytes.
bool BSProceduralLightningController::RegisterStreamables(NiStream& a_stream)
{
    bool result = NiTimeController_RegisterStreamables(this, a_stream);
    if (result) {
        NiInterpolator** slot = interpolators;
        for (std::size_t i = 9; i != 0; --i) {
            if (*slot) {
                (*slot)->RegisterStreamables(a_stream);
            }
            ++slot;
        }
        if (object100) {
            object100->RegisterStreamables(a_stream);
        }
    }
    return result;
}

// Retained generated leaf; its byte-match evidence is renewed with this unit.
// GetInterpolatorCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t BSProceduralLightningController::GetInterpolatorCount() const
{
    return 0x9;
}
