// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the pinned image listing only Stamped as a twin of matched 0x3202d0 (skyrim_shared/forms/BGSListForm): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// 0x24aee0 Owner24aee0::Function24aee0
// member: GUESS(low) STANDIN
#include "Owner24aee0.h"

// guess: same compiled code as matched 0x3202d0 apart from relocated fields; its role here is not established.
const TESForm* Owner24aee0::Function24aee0(std::uint32_t a_index) const
{
    if (a_index < member) {
        return entries[a_index];
    }
    return nullptr;
}
