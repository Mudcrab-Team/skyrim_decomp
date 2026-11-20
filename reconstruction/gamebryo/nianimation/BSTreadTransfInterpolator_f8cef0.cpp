// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf8cef0 BSTreadTransfInterpolator::ctor
// 0xf8d050 BSTreadTransfInterpolator::GetKeyCount
// 0xf8d070 BSTreadTransfInterpolator::GetKeyType
// 0xf8d090 BSTreadTransfInterpolator::GetKeyContent
// 0xf8d0a0 BSTreadTransfInterpolator::GetKeyArray
// 0xf8d0c0 BSTreadTransfInterpolator::GetKeyStride
// 0xf8d0e0 BSTreadTransfInterpolator::GetChannelPosed
#include "BSTreadTransfInterpolator_f8cef0.h"


BSTreadTransfInterpolator::BSTreadTransfInterpolator()
{

}

std::uint32_t BSTreadTransfInterpolator::GetKeyCount(std::uint16_t channel) const
{
    if (channel == 0 && track) {
        return track->numKeys;
    }
    return 0;
}

KeyType BSTreadTransfInterpolator::GetKeyType(std::uint16_t channel) const
{
    if (channel == 0 && track) {
        return track->type;
    }
    return KeyType::kNoInterp;
}

KeyContent BSTreadTransfInterpolator::GetKeyContent(std::uint16_t channel) const
{
    return channel == 0 ? KeyContent::kFloat : KeyContent::kTotal;
}

void* BSTreadTransfInterpolator::GetKeyArray(std::uint16_t channel) const
{
    if (channel == 0 && track) {
        return track->keys;
    }
    return nullptr;
}

std::uint8_t BSTreadTransfInterpolator::GetKeyStride(std::uint16_t channel) const
{
    if (channel == 0 && track) {
        return track->keySize;
    }
    return 0;
}

bool BSTreadTransfInterpolator::GetChannelPosed(std::uint16_t channel) const
{
    if (track) {
        GetKeyCount(channel);
    }
    return false;
}
