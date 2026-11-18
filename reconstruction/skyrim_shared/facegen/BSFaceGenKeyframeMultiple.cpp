// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: the two range predicates conservatively carry sibling attribution for the
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/facegen/bsfacegenkeyframe.cpp:59
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/facegen/bsfacegenkeyframe.cpp:82
// Unk_0B, Unk_0E: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); implementation context only
// 0x43aca0 BSFaceGenKeyframeMultiple::GetExpressionName
// 0x43ace0 BSFaceGenKeyframeMultiple::GetPhonemeName
// 0x432080 BSFaceGenKeyframeMultiple::Unk_0E
// 0x432030 BSFaceGenKeyframeMultiple::Unk_0B
#include "BSFaceGenKeyframeMultiple.h"

// RVA 0x43ad00, 22 bytes: only index 0 has a name.


// RVA 0x43aca0, 23 bytes: indices up to 16 have names.
const char* BSFaceGenKeyframeMultiple::GetExpressionName(std::uint32_t a_index)
{
    if (a_index <= 0x10) {
        // The public unsigned input has been bounded; its signed table index is representable.
        const std::int32_t tableIndex = static_cast<std::int32_t>(a_index);
        return g_expressionNameTable[tableIndex];
    }
    return nullptr;
}

// RVA 0x43ace0, 23 bytes: indices up to 15 have names.
const char* BSFaceGenKeyframeMultiple::GetPhonemeName(std::uint32_t a_index)
{
    if (a_index <= 0xF) {
        // The public unsigned input has been bounded; its signed table index is representable.
        const std::int32_t tableIndex = static_cast<std::int32_t>(a_index);
        return g_phonemeNameTable[tableIndex];
    }
    return nullptr;
}

// RVA 0x432080, 39 bytes: the weight at the index is in [0, 1].
bool BSFaceGenKeyframeMultiple::Unk_0E(std::uint32_t a_index)
{
    if (a_index < count) {
        float weight = values[a_index];
        if (weight >= 0.0f) {
            if (weight > 1.0f) {
                return false;
            }
            return true;
        }
    }
    return false;
}

// RVA 0x432030, 68 bytes: true when some weight is in (0, 1].
bool BSFaceGenKeyframeMultiple::Unk_0B()
{
    for (std::uint32_t i = 0; i < count; ++i) {
        float weight = values[i];
        if (weight >= 0.0f) {
            if (weight > 1.0f) {
                continue;
            }
            if (weight > 0.0f) {
                return true;
            }
        }
    }
    return false;
}

// RVA 0x431da0, 100 bytes: false when a valid index has a positive weight.


// RVA 0x431d20, 108 bytes: the largest weight among the valid indices, or zero.


// Accepted leaf retained from the integrated version.
// Unk_0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint8_t BSFaceGenKeyframeMultiple::Unk_0C() const
{
    return 0x1;
}
