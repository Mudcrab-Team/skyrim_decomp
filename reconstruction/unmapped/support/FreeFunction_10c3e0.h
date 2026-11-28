// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// StringView10c3e0, Function10c3e0: GUESS(low) STANDIN
#pragma once

struct StringView10c3e0
{
    const char* c_str() const { return data ? data : ""; }
    int CompareNoCase(const char* a_other) const;

    const char* data;  // 0x00
};

bool Function10c3e0(const StringView10c3e0& a_lhs, const StringView10c3e0& a_rhs);  // compared: 0x10c3e0
