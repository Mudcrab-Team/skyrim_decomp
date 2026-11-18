// Code origin: Bodies for the DoGet accessors and InitializeData written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x328e60 BGSReverbParameters::DoGetRoomLevel
// 0x328e70 BGSReverbParameters::DoGetRoomHFLevel
// 0x328ec0 BGSReverbParameters::DoGetReflectionLevel
// 0x328ef0 BGSReverbParameters::DoGetReverbLevel
// 0x328f20 BGSReverbParameters::DoGetDiffusion
// 0x328f40 BGSReverbParameters::DoGetDensity
// 0x328f60 BGSReverbParameters::DoGetHFReference
// 0x328e80 BGSReverbParameters::DoGetDecayTime
// 0x328ea0 BGSReverbParameters::DoGetDecayHFRatio
// 0x328ed0 BGSReverbParameters::DoGetReflectionDelay
// 0x328bf0 BGSReverbParameters::InitializeData
#include "BGSReverbParameters.h"
int BGSReverbParameters::DoGetRoomLevel() const { return data.roomFilter * 100; }
int BGSReverbParameters::DoGetRoomHFLevel() const { return data.roomHFFilter * 100; }
int BGSReverbParameters::DoGetReflectionLevel() const { return data.reflections * 100; }
int BGSReverbParameters::DoGetReverbLevel() const { return data.reverb * 100; }
float BGSReverbParameters::DoGetDiffusion() const { return static_cast<float>(data.diffusionPct); }
float BGSReverbParameters::DoGetDensity() const { return static_cast<float>(data.densityPct); }
float BGSReverbParameters::DoGetHFReference() const { return static_cast<float>(data.hfReference); }
float BGSReverbParameters::DoGetDecayTime() const { return static_cast<float>(data.decayTime) * kDecayTimeScale; }
float BGSReverbParameters::DoGetDecayHFRatio() const { return static_cast<float>(data.decayHFRatio) * 0.01f; }
float BGSReverbParameters::DoGetReflectionDelay() const { return static_cast<float>(data.reflectionDelay) * kReflectionDelayScale; }
void BGSReverbParameters::InitializeData()
{
    data.decayTime = 1250;
    data.hfReference = 800;
    data.roomFilter = 100;
    data.roomHFFilter = 100;
    data.reflections = 0;
    data.reverb = 0;
    data.decayHFRatio = 100;
    data.reflectionDelay = 0;
    data.reverbDelay = 0;
    data.diffusionPct = 100;
}
