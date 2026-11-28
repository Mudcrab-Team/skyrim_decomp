// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// StringView10cc60, Function10cc60: GUESS(low) STANDIN
#pragma once

struct StringView10cc60
{
    const char* c_str() const { return data ? data : ""; }
    int CompareNoCase(const char* a_other) const;

    const char* data;  // 0x00
};

bool Function10cc60(const StringView10cc60& a_lhs, const StringView10cc60& a_rhs);  // compared: 0x10cc60
