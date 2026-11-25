// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSPortalGraphEntry, ClearRoomAccumList: CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBoundRoom, multiBoundRoomAccumList: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject, NiRefObject::DeleteThis, NiRefObject::DecRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RoomReference, RoomArray, refCount: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void DecRefCount()
    {
        // Room references can be released concurrently.
        const unsigned int remaining = _InterlockedDecrement(&refCount);
        if (remaining == 0) {
            DeleteThis();
        }
    }

    long refCount;
};

class BSMultiBoundRoom : public NiRefObject {};

struct RoomReference
{
    BSMultiBoundRoom* room;

    ~RoomReference()
    {
        if (room) {
            room->DecRefCount();
        }
    }
};

struct RoomArray
{
    RoomReference* data;
    unsigned char unknown08[8];
    unsigned int size;
};

class BSPortalGraphEntry
{
public:
    void ClearRoomAccumList();
private:
    unsigned char unknown00[0x18];
    RoomArray multiBoundRoomAccumList;
};
