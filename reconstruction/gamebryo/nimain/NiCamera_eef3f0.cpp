// DeleteThis, DecRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 0xeef3f0 29
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// NiCamera, NiPointer, NiAVObject, LinkObject, NiStream, NiRefObject: CRASHLOGGER_PDB(59818@2026.10.24)
// ReadLinkID, ReadLinkIDCount: GUESS(low)
// 0xeef3f0 NiCamera::LinkObject
// CI hash: 0xeef3f0 ?LinkObject@NiCamera@@QEAAXAEAVNiStream@@@Z
#include "NiCamera_eef3f0.h"

void NiCamera::LinkObject(NiStream& stream)
{
    NiAVObject::LinkObject(stream);
    NiPointer<NiRefObject> first(stream.ReadLinkID());
    if (unsigned count = stream.ReadLinkIDCount()) {
        unsigned long long remaining = count;
        do {
            NiPointer<NiRefObject> link(stream.ReadLinkID());
        } while (--remaining);
    }
    if (unsigned count = stream.ReadLinkIDCount()) {
        unsigned long long remaining = count;
        do {
            NiPointer<NiRefObject> link(stream.ReadLinkID());
        } while (--remaining);
    }
}
