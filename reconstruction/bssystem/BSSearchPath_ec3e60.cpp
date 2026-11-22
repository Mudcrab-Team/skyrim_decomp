// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSSearchPath","rationale":"vtable owner and slot; method spelling invented","slot":3},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSSearchPath: EXE_RTTI
// Slot3: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// Code origin: Slot3 from the bounded leaf template; GetNextSearchPath reconstructed from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0xec3e60 BSSearchPath::GetNextSearchPath
#include "BSSearchPath_ec3e60.h"

#include <cstring>
// Slot3: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t BSSearchPath::Slot3() const
{
    return 0x1;
}

bool BSSearchPath::GetNextSearchPath(char* a_dest, std::uint32_t)
{
    if (nextIndex != 0) {
        return false;
    }
    strcpy_s(a_dest, sizeof(path), path);
    ++nextIndex;
    return true;
}
