// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the key channel and interpolator prefix follow the cited declarations and pinned offsets.
// BSTreadTransfInterpolator: EXE_RTTI
// NiKeyBasedInterpolator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetKeyChannelCount, GetKeyCount, GetKeyType, GetKeyContent, GetKeyArray, GetKeyStride, GetChannelPosed: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// track, trackAux, trackStart, trackEnd: GUESS(low)
#pragma once

#include <cstdint>
#include "NiKeyBasedInterpolator.h"

// KeyType, KeyContent, kNoInterp, kFloat, kPos, kTotal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
enum class KeyContent : std::int32_t { kFloat = 0, kPos = 1, kTotal = 6 };
enum class KeyType : std::int32_t { kNoInterp = 0 };

// TrackKeyData: STANDIN GUESS(low); count, key pointer, type, and stride are used by the channel methods.
class TrackKeyData : public NiObject
{
public:
    std::uint32_t numKeys;
    std::uint32_t padding14;
    void* keys;
    KeyType type;
    std::uint8_t keySize;
};

class BSTreadTransfInterpolator : public NiKeyBasedInterpolator
{
public:
    BSTreadTransfInterpolator();
    virtual std::uint16_t GetKeyChannelCount() const;
    virtual std::uint32_t GetKeyCount(std::uint16_t channel) const;
    virtual KeyContent GetKeyContent(std::uint16_t channel) const;
    virtual KeyType GetKeyType(std::uint16_t channel) const;
    virtual void* GetKeyArray(std::uint16_t channel) const;
    virtual std::uint8_t GetKeyStride(std::uint16_t channel) const;
    virtual bool GetChannelPosed(std::uint16_t channel) const;

private:
    void* trackAux{};
    void* trackStart{};
    void* trackEnd{};
    TrackKeyData* track{};
};
static_assert(sizeof(BSTreadTransfInterpolator) == 0x38, "tread interpolator size");
