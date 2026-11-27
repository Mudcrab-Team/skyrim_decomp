// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageDataTopic.cpp:47
// BGSPackageDataTopic::Copy: SIBLING(fo4-private@1b765c70, author-permission); the Skyrim slot is Assign
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSPackageDataTopic, IPackageData, IPackageData::Assign: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN OBSERVED; NG declares Assign with a non-const parameter
// BGSTopicSubtypeUnion, BGSTopicSubtypeUnion::Copy: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; only its size and Copy are used
// BGSPackageDataTopic::nameAndFlags, BGSPackageDataTopic::data: GUESS(low)
#pragma once

#include <cstdint>

class IPackageData
{
public:
    virtual ~IPackageData();
    virtual void Assign(const IPackageData* a_other);  // 03
};

class BGSTopicSubtypeUnion
{
public:
    void Copy(const BGSTopicSubtypeUnion* a_other);

    std::uint64_t unknown00[1];  // 00
};

class BGSPackageDataTopic : public IPackageData
{
public:
    void Assign(const IPackageData* a_other) override;

    std::uint64_t nameAndFlags;  // 08
    BGSTopicSubtypeUnion data;   // 10
};
