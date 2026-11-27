// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSVisitProceduresInitActorLocation: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// BGSVisitProceduresInitActorLocation::Function4964f0: GUESS(low)
// BGSVisitProceduresInitActorLocation::unknown0, BGSVisitProceduresInitActorLocation::unk10, BGSVisitProceduresInitActorLocation::unknown18, BGSVisitProceduresInitActorLocation::unk20: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class BGSVisitProceduresInitActorLocation
{
public:
    void Function4964f0(void* value);
    std::uint8_t unknown0[16];
    void* unk10;
    std::uint8_t unknown18[8];
    std::uint8_t unk20;
};
static_assert(offsetof(BGSVisitProceduresInitActorLocation, unk10) == 16, "field offset");
static_assert(offsetof(BGSVisitProceduresInitActorLocation, unk20) == 32, "field offset");
