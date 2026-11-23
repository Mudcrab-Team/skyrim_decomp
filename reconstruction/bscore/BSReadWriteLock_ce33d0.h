// Source exposure: mixed (community headers; the pinned image listing)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSReadWriteLock, LockForWrite, _writerThread, _lock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name taken for the behaviour, not confirmed by address
#pragma once
#include <cstdint>

class BSReadWriteLock
{
public:
    void LockForWrite();  // compared: 0xce33d0

    std::uint32_t _writerThread;           // 0
    std::uint32_t _lock;                   // 4
};
