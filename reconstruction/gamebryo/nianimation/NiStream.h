// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial stream interface from the cited public declaration.
// NiStream, SaveLinkID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BSFixedString;
class NiBinaryStream;
class NiObject;

class NiStream
{
public:
    virtual ~NiStream();
    virtual bool Load1(NiBinaryStream* stream);
    virtual bool Load2(char* buffer, std::uint64_t length);
    virtual bool Load3(const char* path);
    virtual bool Save1(NiBinaryStream* stream);
    virtual bool Save2(char*& path, std::uint64_t& length);
    virtual bool Save3(const char* path);
    virtual bool Unk_07();
    virtual bool RegisterFixedString(const BSFixedString& value);
    virtual bool RegisterSaveObject(NiObject* object);
    virtual bool ChangeObject(NiObject* object);
    virtual std::uint32_t GetLinkIDFromObject(const NiObject* object);
    virtual void SaveLinkID(const NiObject* object);
};
