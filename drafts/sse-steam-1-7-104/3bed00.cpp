// Near miss: 1.0 alignment distance | control-flow
// Exposure detail: (permitted sibling game code; pinned-image observations).
// Source exposure: mixed
// Code origin: adapted from labelled sibling game code with target-observed layout
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: TESNPC::HasAssociationType from fo4-private@1b765c70 (author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/TESNPC.cpp:659
// TESNPC::HasAssociationType body: SIBLING(fo4-private@1b765c70, author-permission)
// 0x3bed00 TESNPC::HasAssociationType

#include "include/3bed00/TESNPC_3bed00.h"

bool TESNPC::HasAssociationType(BGSAssociationType* type) const
{
    auto* array = relationships;
    if (array) {
        auto count = array->count;
        std::int16_t found = false;
        if (count) {
            auto* cursor = array->data;
            auto* end = cursor + count;
            for (; cursor != end;) {
                auto* relationship = *cursor;
                if (relationship && relationship->associationType == type) {
                    found = true;
                    break;
                }
                ++cursor;
            }
        }
        return found;
    } else {
    return false;
}
}
