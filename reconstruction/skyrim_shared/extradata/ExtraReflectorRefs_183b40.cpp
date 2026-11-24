// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x183b40 ExtraReflectorRefs::IsNotEqual
// Adapted bodies: none
#include "ExtraReflectorRefs_183b40.h"

bool ExtraReflectorRefs::IsNotEqual(const BSExtraData* a_rhs) const
{
    const ExtraReflectorRefs* rhs = static_cast<const ExtraReflectorRefs*>(a_rhs);
    bool equal = false;
    if (rhs->refs.size == refs.size) {
        equal = true;
        for (std::uint32_t i = 0; i < refs.size; ++i) {
            if (!equal) {
                break;
            }
            if (refs.data[i] != rhs->refs.data[i]) {
                equal = false;
            }
        }
    }
    return !equal;
}
