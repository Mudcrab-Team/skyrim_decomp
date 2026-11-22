// Source exposure: mixed (pinned image listing and community declarations).
// 0x1508100 compared function
// SPDX-License-Identifier: CC0-1.0
// Code origin: original implementation from the pinned slot body; the compared body is the compiler-generated scalar deleting destructor from the listing
// Adapted bodies: none
// BSImagespaceShaderCopyCustomViewport: EXE_RTTI
// Unk_0D: GUESS(low)
// unknown08: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <cstddef>

class BSImagespaceShaderCopyCustomViewport
{
public:
    BSImagespaceShaderCopyCustomViewport();           // defined so the vftable and its deleting destructor are emitted
    virtual ~BSImagespaceShaderCopyCustomViewport();  // compared: 0x1508100; declared but left undefined

    const void** Unk_0D(const void** bindings);

    std::uint64_t unknown08[54];  // 08 .. 1b7
};
static_assert(sizeof(BSImagespaceShaderCopyCustomViewport) == 0x1B8, "size observed from the sized delete argument");
