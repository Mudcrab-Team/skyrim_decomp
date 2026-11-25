// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction using labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESTopicInfo, TESForm, FORM, FORM_GROUP: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); accessed layouts only.
// CreateGroupData, parentTopic, formID, form, length, flags, versionControl, groupData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DialogueSignature, GroupSignature: GUESS(low); observed record-signature data references.
#pragma once
#include <cstddef>
#include <cstdint>

struct FORM {
    std::uint32_t form;
    std::uint32_t length;
    std::uint32_t flags;
    std::uint32_t formID;
    std::uint32_t versionControl;
    std::uint16_t formVersion;
    std::uint16_t vcVersion;
};
struct FORM_GROUP {
    FORM groupData;
    std::uint64_t groupOffset;
};
class TESForm {
public:
    std::uint8_t unknown00[0x14];
    std::uint32_t formID;
};
class TESTopicInfo {
public:
    void CreateGroupData(FORM* form, FORM_GROUP* group);
    std::uint8_t unknown00[0x20];
    TESForm* parentTopic;
};
extern const std::uint32_t DialogueSignature;
extern const std::uint32_t GroupSignature;
static_assert(offsetof(TESTopicInfo, parentTopic) == 0x20, "parent topic offset");
static_assert(offsetof(TESForm, formID) == 0x14, "parent form ID offset");
