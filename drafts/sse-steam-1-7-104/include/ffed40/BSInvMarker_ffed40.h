// Code origin: original reconstruction; declaration names from labelled sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSInvMarker, zoom, rotationX, rotationY, rotationZ: CRASHLOGGER_PDB(59818@2026.10.24)
// NiExtraData, NiCloningProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers: GUESS(low); cloning copy role
// prefix: GUESS(low); unrepresented base storage
// 0xffed40 BSInvMarker::CopyMembers

#pragma once
#include <cstddef>
class NiCloningProcess;
class NiExtraData {
public:
    void CopyMembers(NiExtraData* destination, NiCloningProcess& process);
    unsigned char prefix[0x18];
};
class BSInvMarker : public NiExtraData {
public:
    void CopyMembers(BSInvMarker* destination, NiCloningProcess& process);
    float zoom;
    unsigned short rotationX;
    unsigned short rotationY;
    unsigned short rotationZ;
};
static_assert(offsetof(BSInvMarker, zoom) == 0x18, "zoom offset");
static_assert(offsetof(BSInvMarker, rotationX) == 0x1c, "rotationX offset");
static_assert(offsetof(BSInvMarker, rotationY) == 0x1e, "rotationY offset");
static_assert(offsetof(BSInvMarker, rotationZ) == 0x20, "rotationZ offset");
