// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// UIBlurManager, UIBlurManager::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// SingletonBase98cb10, gUIBlurManager, Cleanup: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

class UIBlurManager;
extern UIBlurManager* gUIBlurManager;

class SingletonBase98cb10
{
public:
    virtual ~SingletonBase98cb10()
    {
        gUIBlurManager = nullptr;
    }
};

class UIBlurManager : public SingletonBase98cb10
{
public:
    UIBlurManager();
    virtual ~UIBlurManager() override;

    void Cleanup();

    std::uint8_t unk08[0x18];  // 08
};
static_assert(sizeof(UIBlurManager) == 0x20, "UIBlurManager size");
