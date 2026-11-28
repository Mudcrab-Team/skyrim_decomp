// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// KeyInterface_d068f0, ResourceKey_d068f0: GUESS(low) STANDIN
#pragma once

struct KeyInterface_d068f0
{
    virtual ~KeyInterface_d068f0();
    virtual void AddRef(void* a_data);
};

struct ResourceKey_d068f0
{
    ResourceKey_d068f0(const ResourceKey_d068f0& a_other);  // compared: 0xd068f0

    KeyInterface_d068f0* keyInterface;  // 0x00
    void* keyData;                      // 0x08
};
