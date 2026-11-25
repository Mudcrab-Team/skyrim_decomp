// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from local target observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1e5c10 ConvertFormType
// Adapted bodies: none.
#include "TESForm_1e5c10.h"

FormType ConvertFormType(std::uint32_t recordType)
{
    if (recordType == cachedRecordType) {
        return cachedFormType;
    }
    for (std::uint32_t index = 0; index < 138; ++index) {
        if (formTypeRecords[index].recordType == recordType) {
            cachedFormType = static_cast<FormType>(index);
            cachedRecordType = recordType;
            return static_cast<FormType>(index);
        }
    }
    return FormType::None;
}
