// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiIntegersExtraData: EXE_RTTI
// NiIntegersExtraData::size, NiIntegersExtraData::value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetValues, FreeExtraData, AllocateExtraData: GUESS(low)
#pragma once

#include "NiExtraData_ef9840.h"

class NiIntegersExtraData : public NiExtraData
{
public:
    void SetValues(std::uint32_t count, const std::int32_t* elements);

private:
    std::uint32_t size;
    std::int32_t* value;
};
