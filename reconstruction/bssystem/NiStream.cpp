// Source exposure: mixed (names and declarations from community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xee6f60 NiStream::LoadObjectSizeTable
// Adapted bodies: none
// 0xee4710 Leafee4710::Invoke
// 0xee4350 NiStream::Save1
// 0xee9550 NiStream::~NiStream
#include "NiStream.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
NiStream::NiStream()
{
}

// Unk_07: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void NiStream::Unk_07()
{
}

// Save1: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void NiStream::Save1(NiBinaryStream* a_stream)
{
    streamPtr2A0 = a_stream;
    Unk_10();
    streamPtr2A0 = nullptr;
}

// LoadObjectSizeTable: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Reads one size word per object in the object list into the size table and keeps the table's used
// entry count in step with entries that become zero or leave zero.
bool NiStream::LoadObjectSizeTable()
{
    objectSizes.SetEntryCount(objects._freeIdx);

    for (std::uint32_t i = 0; i < objects._freeIdx; ++i) {
        std::uint32_t size = 0;
        iStr->read(&size, 1);

        if (i >= objectSizes._freeIdx) {
            objectSizes._freeIdx = i + 1;
            if (size != 0) {
                ++objectSizes._size;
            }
        } else {
            const std::uint32_t previous = objectSizes._data[i];
            if (size != 0) {
                if (previous == 0) {
                    ++objectSizes._size;
                }
            } else if (previous != 0) {
                --objectSizes._size;
            }
        }

        objectSizes._data[i] = size;
    }

    return true;
}
