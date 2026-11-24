// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0xf9e760 NiMeshParticleSystem::UpdateDownwardPass
// Adapted bodies: TestBit parallels momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (CC0-1.0); spelling follows cookbook rule 16
#include "NiMeshParticleSystem_f9e760.h"
void NiMeshParticleSystem::UpdateDownwardPass(NiUpdateData& data, std::uint32_t arg) {
    if (TestBit(data.flags, 1)) data.flags |= 0x100;
    else { NiParticleSystem::UpdateSelectedDownwardPass(data, arg); savedTime = data.time; }
}
