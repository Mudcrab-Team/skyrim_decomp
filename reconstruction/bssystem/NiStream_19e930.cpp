// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build.
// 0x19e930 NiStream::SaveLinkID
// 0xee4420 NiStream::Load3
// 0xee46d0 NiStream::ClearLoadContext
// 0xee5060 NiStream::GetLinkIDFromObject
// 0xee69c0 NiStream::RegisterObjects
// 0xee6bc0 NiStream::SaveTopLevelObjects
// 0xee6e40 NiStream::PreSaveObjectSizeTable
// 0xf12a70 NiStream::ReadIntegers
// 0xf12ab0 NiStream::WriteIntegers
#include "NiStream_19e930.h"

#include <cstring>

void NiStream::SaveLinkID(const NiObject* object)
{
    auto id = GetLinkIDFromObject(object);
    auto* binary = oStr;
    std::uint32_t width = sizeof(std::uint32_t);
    const auto transferred = binary->_writeFn(binary, &id, sizeof(std::uint32_t), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool NiStream::Load3(const char* path)
{
    iStr = nullptr;
    strcpy_s(inputFilePath, sizeof(inputFilePath), path);
    return LoadFromInputPath();
}

void NiStream::ClearLoadContext()
{
    delete loadContext;
    loadContext = nullptr;
    loadState = 0;
}

std::uint32_t NiStream::GetLinkIDFromObject(const NiObject* object)
{
    constexpr std::uint32_t missing = 0xFFFFFFFFu;
    if (!object) {
        return missing;
    }
    auto id = missing;
    auto* map = &registerMap;
    const auto bucket = map->BucketFor(object);
    auto* entry = map->buckets[bucket];
    while (entry) {
        if (map->IsSameObject(object, entry->object)) {
            id = entry->id;
            break;
        }
        entry = entry->next;
    }
    return id;
}

void NiStream::RegisterObjects()
{
    for (std::uint32_t i = 0; i < topObjectCount; ++i) {
        topObjects[i]->RegisterStreamables(*this);
    }
}

void NiStream::SaveTopLevelObjects()
{
    auto count = topObjectCount;
    auto* binary = oStr;
    std::uint32_t width = sizeof(std::uint32_t);
    const auto transferred = binary->_writeFn(binary, &count, sizeof(std::uint32_t), &width, 1);
    binary->_absoluteCurrentPos += transferred;
    for (std::uint32_t i = 0; i < count; ++i) {
        SaveLinkID(topObjects[i]);
    }
}

std::uint32_t NiStream::PreSaveObjectSizeTable()
{
    auto start = oStr->tell();
    std::uint32_t entrySize = 0;
    for (std::uint32_t i = 0; i < objectCount; ++i) {
        auto* binary = oStr;
        std::uint32_t width = sizeof(std::uint32_t);
        const auto transferred = binary->_writeFn(binary, &entrySize, sizeof(std::uint32_t), &width, 1);
        binary->_absoluteCurrentPos += transferred;
    }
    return start;
}

void NiStream::ReadIntegers(std::uint32_t* values, std::uint32_t count)
{
    auto* binary = iStr;
    std::uint32_t width = sizeof(*values);
    const auto transferred = binary->_readFn(binary, values, count * sizeof(*values), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiStream::WriteIntegers(const std::uint32_t* values, std::uint32_t count)
{
    auto* binary = oStr;
    std::uint32_t width = sizeof(*values);
    const auto transferred = binary->_writeFn(binary, values, count * sizeof(*values), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}
