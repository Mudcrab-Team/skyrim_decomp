// Code origin: original drafting by Hinkiii from a local listing of the pinned image; names and declarations Stamped as a twin of matched 0xcea710 (bscore/BSSmallBlockAllocator): source copied, names replaced by placeholders.
// from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); no body is copied from any source.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcea520 Ownercea520::ContainsBlockImpl
#include "Ownercea520.h"

// guess: same compiled code as matched 0xcea710 apart from relocated fields; its role here is not established.
bool Ownercea520::ContainsBlockImpl(const void* a_block) const
{
    const char* block = static_cast<const char*>(a_block);
    return block >= allocBase && block < blockPageCommit;
}
