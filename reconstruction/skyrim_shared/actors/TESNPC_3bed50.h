// Source exposure: mixed (community declarations; permitted sibling game code; pinned-image observations).
// Code origin: original declarations with observed partial layouts
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESNPC, TESNPC::HasFamilyRelationship: SIBLING(fo4-private@1b765c70, author-permission)
// BGSAssociationType, BGSRelationship, relationships, assocType, flags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RelationshipArray, data, count, prefix, gap08: STANDIN GUESS(low); partial array layout
#pragma once
#include <cstdint>
#include <cstddef>
struct BGSAssociationType {
    std::uint8_t prefix[0x40];
    std::uint8_t flags; // Only the observed low byte is inspected here.
};
struct BGSRelationship {
    std::uint8_t prefix[0x30];
    BGSAssociationType* assocType;
};
struct RelationshipArray {
    BGSRelationship** data;
    std::uint8_t gap08[8];
    std::uint32_t count;
};
class TESNPC {
public:
    bool HasFamilyRelationship() const;
    std::uint8_t prefix[0x250];
    RelationshipArray* relationships;
};
static_assert(offsetof(TESNPC, relationships) == 0x250, "relationship array offset");
static_assert(offsetof(BGSRelationship, assocType) == 0x30, "association offset");
static_assert(offsetof(BGSAssociationType, flags) == 0x40, "association flags offset");
