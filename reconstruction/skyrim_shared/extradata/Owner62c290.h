// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1865e0 (skyrim_shared/extradata/ExtraPackageData_1865e0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// Owner62c290: GUESS(low) STANDIN
// BSExtraData: GUESS(low) STANDIN
#pragma once
#include "ExtraPackageData_1865e0.h"

class Owner62c290 : public BSExtraData
{
public:
    ~Owner62c290() override;

    ActorPackageData* packageData;  // 0x10
    std::uint64_t unk18;
};
static_assert(sizeof(Owner62c290) == 32, "Owner62c290 size");
