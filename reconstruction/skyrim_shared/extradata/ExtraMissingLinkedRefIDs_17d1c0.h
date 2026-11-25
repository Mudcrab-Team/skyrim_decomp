// Source exposure: mixed (pinned image analysis and community declarations).
// Code origin: original hand-written reconstruction; declarations adapted from the labelled community header.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraMissingLinkedRefIDs, ExtraMissingLinkedRefIDs::~ExtraMissingLinkedRefIDs, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Array::~Array: GUESS(low); original ownership helper inferred from cleanup
// Entry, Array, entries, _data, _size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraMissingLinkedRefIDs::ExtraMissingLinkedRefIDs: GUESS(low); stand-in constructor to emit the virtual table
// BSExtraData::unknown08: GUESS(low); unaccessed base storage
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

class ExtraMissingLinkedRefIDs : public BSExtraData
{
public:
    ExtraMissingLinkedRefIDs();
    ~ExtraMissingLinkedRefIDs() override = default;

    struct Entry
    {
        void* keyword;
        std::uint32_t linkedRefID;
        std::uint32_t pad0C;
    };
    struct Array
    {
        ~Array()
        {
            if (_size > 1) {
                ::operator delete(_data.entryPtr, sizeof(Entry));
            }
            _data.entryPtr = nullptr;
            _size = 0;
        }

        union Data
        {
            Entry* entryPtr;
            Entry entry[1];
        } _data;
        std::uint32_t _size;
        std::uint32_t _pad14;
    };
    Array entries;  // 10
};
static_assert(sizeof(ExtraMissingLinkedRefIDs) == 0x28, "ExtraMissingLinkedRefIDs size");
// 0x17d1c0 ExtraMissingLinkedRefIDs::~ExtraMissingLinkedRefIDs
