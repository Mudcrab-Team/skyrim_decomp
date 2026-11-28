// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Entry_f6fd10, HelperA_f6fd10, HelperB_f6fd10, Functionf6fd10, unk00, field04, target, entry, fieldPtr: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Entry_f6fd10
{
    std::uint32_t unk00;    // 0x00
    std::uint32_t field04;  // 0x04
};
static_assert(offsetof(Entry_f6fd10, field04) == 0x04, "field04 offset");

void HelperA_f6fd10(void* target, Entry_f6fd10* entry);
void HelperB_f6fd10(std::uint32_t* fieldPtr, void* target);

void Functionf6fd10(void* target, Entry_f6fd10* entry);
