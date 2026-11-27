// Source exposure: binary-analysis (class names from the image's RTTI; sizes and the inlined destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// AsyncOperationProxy: EXE_RTTI; a type of the online services library in the image
// AsyncOperationProxy::unk00, unk01, unk02, unk08, AsyncOperationHandle: GUESS(low); virtual slot placeholders, an unknown field and the member type at 0x10 whose destructor stays out of line
#pragma once

class AsyncOperationHandle
{
public:
    ~AsyncOperationHandle();

    unsigned char unk00[0x18];  // 00
};

class AsyncOperationProxy
{
public:
    AsyncOperationProxy();
    virtual void unk00();  // 00
    virtual void unk01();  // 01
    virtual void unk02();  // 02
    virtual ~AsyncOperationProxy() = default;  // 03

    unsigned char unk08[0x8];  // 08
    AsyncOperationHandle unk10;  // 10
};
static_assert(sizeof(AsyncOperationProxy) == 0x28, "size from the deleting destructor");
