// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from pinned-image behavior
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFile, file, isGood, mode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); owner inferred from observed file layout
// Functionebebb0, Functioneade30, Functionebeae0, unknown00: GUESS(low) STANDIN; helper roles and unaccessed prefix not established
#pragma once
#include <cstddef>
#include <cstdint>
#include <cstdio>

class NiFile
{
public:
    void Functionebebb0();
    void Functioneade30();
    void Functionebeae0();

    std::uint8_t unknown00[0x38];
    std::FILE* file;
    std::uint32_t mode;
    bool isGood;
};
static_assert(offsetof(NiFile, file) == 0x38, "file offset");
static_assert(offsetof(NiFile, isGood) == 0x44, "isGood offset");
