// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1e5d10 TESForm::GetFormDetailedString_1401947A0
// Adapted bodies: none
#include "TESForm_1e5d10.h"

// Formats the form type name and form ID into the caller-supplied buffer.
void TESForm::GetFormDetailedString_1401947A0(char* a_buf, std::uint32_t a_bufLen)
{
    FormatString(a_buf, a_bufLen, g_formDetailedFormat, g_formTypeNames[formType].name, g_emptyString, formID);
}
