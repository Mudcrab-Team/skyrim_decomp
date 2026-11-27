// Source exposure: mixed (community declarations; permitted sibling game code; pinned-image observations).
// Code origin: adapted sibling query with target-observed layout and predicate
// Adapted bodies: TESNPC::HasFamilyRelationship from fo4-private@1b765c70 (author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/TESNPC.cpp:672
// TESNPC::HasFamilyRelationship body: SIBLING(fo4-private@1b765c70, author-permission)
// 0x3bed50 TESNPC::HasFamilyRelationship
#include "TESNPC_3bed50.h"

// Check whether any relationship association carries the family flag.
bool TESNPC::HasFamilyRelationship() const
{
    auto* array = relationships;
    if (array) {
        auto count = array->count;
        bool found = false;
        if (count) {
            auto* cursor = array->data;
            auto* end = cursor + count;
            while (cursor != end) {
                auto* relationship = *cursor;
                if (relationship && relationship->assocType && (relationship->assocType->flags & 1) != 0) {
                    found = true;
                    break;
                }
                ++cursor;
            }
        }
        return found;
    }
    return false;
}
