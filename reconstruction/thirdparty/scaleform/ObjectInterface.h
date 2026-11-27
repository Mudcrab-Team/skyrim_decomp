// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GFxValue, GFxValue::ObjectInterface, GFxValue::ObjectInterface::GetArraySize, GFxValue::ObjectInterface::_movieRoot, GFxMovieRoot, a_data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GASArrayObject, GASArrayObject::unk68, GASArrayObject::unk70, GASArrayObject::unk78: STANDIN GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "GASObject.h"

class GFxMovieRoot;

class GFxValue
{
public:
    class ObjectInterface
    {
    public:
        std::uint32_t GetArraySize(void* a_data) const;

        GFxMovieRoot* _movieRoot;  // 00
    };
    static_assert(sizeof(ObjectInterface) == 0x8, "GFxValue::ObjectInterface size");
};

// An ActionScript array object; the element count follows the object members.
class GASArrayObject : public GASObject
{
public:
    std::uint64_t unk68;  // 68
    std::uint64_t unk70;  // 70
    std::uint32_t unk78;  // 78 - element count
};
