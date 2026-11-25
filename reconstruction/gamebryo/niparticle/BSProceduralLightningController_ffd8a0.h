// SPDX-License-Identifier: GPL-3.0
// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SetInterpolator: SIBLING(fo4-private@1b765c70, author-permission)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSProceduralLightningController, interpolators: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// SetInterpolator: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiInterpolator, DeleteThis, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>
#include <cstdint>

class NiInterpolator {
public:
    virtual ~NiInterpolator();
    virtual void DeleteThis();
    // volatile: reference counter is modified with atomic interlocked operations.
    volatile long _refCount;
};

class BSProceduralLightningController {
public:
    void SetInterpolator(NiInterpolator* interpolator, std::uint16_t index);
    unsigned char prefix[0x108];
    NiInterpolator* interpolators[9];
};
static_assert(offsetof(BSProceduralLightningController, interpolators) == 0x108, "interpolator offset");
