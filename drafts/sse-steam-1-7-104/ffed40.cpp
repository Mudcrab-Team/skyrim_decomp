// Near miss: 0.5 alignment distance | register-schedule
// Code origin: original reconstruction; declaration names from labelled sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSInvMarker: CRASHLOGGER_PDB(59818@2026.10.24)
// CopyMembers: GUESS(low); cloning copy role
// 0xffed40 BSInvMarker::CopyMembers
#include "include/ffed40/BSInvMarker_ffed40.h"
#include <xmmintrin.h>

void BSInvMarker::CopyMembers(BSInvMarker* destination, NiCloningProcess& process)
{
    NiExtraData::CopyMembers(destination, process);
    // SIMD transport preserves the stored float representation.
    const __m128 copiedZoom = _mm_load_ss(&zoom);
    const unsigned short copiedY = rotationY;
    const unsigned short copiedX = rotationX;
    const unsigned short copiedZ = rotationZ;
    // SIMD transport preserves the stored float representation.
    _mm_store_ss(&destination->zoom, copiedZoom);
    destination->rotationX = copiedX;
    destination->rotationY = copiedY;
    destination->rotationZ = copiedZ;
}
