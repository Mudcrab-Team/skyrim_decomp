// Exposure detail: (permitted sibling game code; pinned-image observations).
// Source exposure: mixed
// Code origin: adapted from labelled sibling game code with target-observed layout
// SPDX-License-Identifier: CC0-1.0
// TESNPC, TESNPC::HasAssociationType: SIBLING(fo4-private@1b765c70, author-permission)
// BGSAssociationType, BGSRelationship, RelationshipArray, associationType, relationships: GUESS(low)

#pragma once
#include <cstdint>
struct BGSAssociationType;
struct BGSRelationship {
    std::uint8_t prefix[0x30];
    BGSAssociationType* associationType;
};
struct RelationshipArray {
    BGSRelationship** data;
    std::uint8_t gap08[8];
    std::uint32_t count;
};
class TESNPC {
public:
    bool HasAssociationType(BGSAssociationType* type) const;
    std::uint8_t prefix[0x250];
    RelationshipArray* relationships;
};
