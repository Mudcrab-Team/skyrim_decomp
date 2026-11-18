// BSHandleRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// Source exposure: mixed (binary-analysis, community-headers).
// Community source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Body origin: original reconstruction with the community adaptations stated above.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <intrin.h>
namespace p145 {
// NiRefObject, DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
struct NiRefObject {
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long refCount;
    unsigned reserved;
    void DecRefCount() {
        // References cross threads; the final releaser owns deletion.
        if (_InterlockedExchangeAdd(&refCount, -1) == 1) DeleteThis();
    }
};
// refCount, reserved: GUESS(low) STANDIN
// BSHandleRefObject, DecRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
struct BSHandleRefObject : NiRefObject {
    void DecRefCount() {
        // The atomic count shares its word with handle-state flags.
        if (((_InterlockedExchangeAdd(&refCount, -1) - 1) & 0x3ff) == 0) DeleteThis();
    }
};
}
