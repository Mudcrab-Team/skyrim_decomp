// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// Code origin: SaveBinary and Stop original from the pinned image listing and the declarations in NiPSysModifierCtlr.h
// NiPSysEmitterCtlr: EXE_RTTI
// GetInterpolatorCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// NiPSysEmitterCtlr::SaveBinary, NiPSysEmitterCtlr::Stop: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// visibilityInterpolator, scaledLastTime: GUESS(low); after the visibility interpolator the stream links and the time Stop resets
// padding58, padding68, unk74: GUESS(low); unrecovered members, unk74 cleared with the time on Stop
#pragma once
#include <cstdint>

#include "NiPSysModifierCtlr.h"

// GetInterpolatorCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class NiPSysEmitterCtlr : public NiPSysModifierCtlr
{
public:
    virtual std::uint32_t GetInterpolatorCount() const;
    void SaveBinary(NiStream& stream) override;
    void Stop() override;

private:
    std::uint8_t padding58[0x8];
    NiInterpolator* visibilityInterpolator;  // 60
    std::uint8_t padding68[0x8];
    float scaledLastTime;  // 70
    std::uint32_t unk74;   // 74
};
