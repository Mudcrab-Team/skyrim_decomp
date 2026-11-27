// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1e5ae0 TESForm::GetFile
// Adapted bodies: none
#include "TESForm_1e5ae0.h"

// Returns the TESFile at the given source-file index, clamping out-of-range indices to the last file.
TESFile* TESForm::GetFile(std::int32_t a_idx) const
{
    TESFileArray* array = sourceFiles.array;
    if (!array || array->size <= 0) {
        return nullptr;
    }
    if (a_idx < 0 || a_idx >= array->size) {
        a_idx = array->size - 1;
    }
    return (*array)[a_idx];
}
