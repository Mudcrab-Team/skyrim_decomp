// Source exposure: mixed (pinned image analysis and community declarations).
// Code origin: original hand-written reconstruction; declarations adapted from the labelled community header.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraMissingRefIDs, ExtraMissingRefIDs::~ExtraMissingRefIDs, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActivateParentID, IDs, numIDs: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraMissingRefIDs::ExtraMissingRefIDs: GUESS(low); stand-in constructor to emit the virtual table
// BSExtraData::unknown08: GUESS(low); unaccessed base storage
// IDStorage, IDStorage::~IDStorage, storage: GUESS(low); original ownership helper inferred from cleanup
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    std::uint64_t unknown08;  // 08, unaccessed base storage
};

struct ActivateParentID
{
    std::uint32_t refID;
    float activateDelay;
};

class ExtraMissingRefIDs : public BSExtraData
{
public:
    ExtraMissingRefIDs();
    ~ExtraMissingRefIDs() override = default;

    struct IDStorage
    {
        ~IDStorage()
        {
            if (numIDs > 1) {
                ::operator delete(IDs, sizeof(ActivateParentID));
            }
            IDs = nullptr;
            numIDs = 0;
        }
        ActivateParentID* IDs;
        std::uint32_t numIDs;
        std::uint32_t unk1C;
        std::uint64_t unk20;
    } storage;  // 10
};
static_assert(sizeof(ExtraMissingRefIDs) == 0x28, "ExtraMissingRefIDs size");
// 0x17d220 ExtraMissingRefIDs::~ExtraMissingRefIDs
