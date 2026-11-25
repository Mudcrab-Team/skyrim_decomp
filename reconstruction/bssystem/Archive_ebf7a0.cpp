// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original; declarations reduced from pinned community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Archive, set_endian_swap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: none.
// 0xebf7a0 Archive::set_endian_swap
#include "Archive_ebf7a0.h"

void Archive::set_endian_swap(bool a_doSwap)
{
    if (a_doSwap) {
        _readFn = ReadSwapped;
        _writeFn = WriteSwapped;
    } else {
        _readFn = ReadNative;
        _writeFn = WriteNative;
    }
}
