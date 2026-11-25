// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from local target observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FormType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ConvertFormType, FormTypeRecord, FormTypeRecord::recordType, FormTypeRecord::unknown04, formTypeRecords, cachedRecordType, cachedFormType: GUESS(low)
#pragma once
#include <cstdint>

class TESForm {};

enum class FormType : std::uint32_t { None = 0 };
struct FormTypeRecord
{
    std::uint32_t recordType;
    std::uint8_t unknown04[0x14];
};
static_assert(sizeof(FormTypeRecord) == 0x18, "observed table stride");
extern FormTypeRecord formTypeRecords[138];
extern std::uint32_t cachedRecordType;
extern FormType cachedFormType;
FormType ConvertFormType(std::uint32_t recordType);
