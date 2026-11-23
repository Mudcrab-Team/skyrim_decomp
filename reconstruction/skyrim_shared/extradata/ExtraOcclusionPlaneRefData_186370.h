// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraOcclusionPlaneRefData: EXE_RTTI
// IsNotEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
class ExtraOcclusionPlaneRefData {
public:
    bool IsNotEqual(const ExtraOcclusionPlaneRefData* other) const;
    std::uint64_t unk00, unk08;
    const std::uint32_t* data;
};
