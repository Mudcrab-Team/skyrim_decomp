// DeleteThis, DecRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 0xeef3f0 29
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the pinned image.
// NiCamera, NiPointer, NiAVObject, LinkObject, NiStream, NiRefObject: CRASHLOGGER_PDB(59818@2026.10.24)
// GetObjectFromLinkID, GetNumberOfLinkIDs: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCamera::LinkObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0xeef3f0 NiCamera::LinkObject
// CI hash: 0xeef3f0 ?LinkObject@NiCamera@@QEAAXAEAVNiStream@@@Z
#include "NiCamera_eef3f0.h"

// The pinned routine forwards one stream by reference. CommonLib declares this override
// with a void result. CrashLogger associates an unrelated Explosion prototype with this RVA.
void NiCamera::LinkObject(NiStream& stream)
{
    NiAVObject::LinkObject(stream);
    NiPointer<NiRefObject> first(stream.GetObjectFromLinkID());
    if (unsigned count = stream.GetNumberOfLinkIDs()) {
        unsigned long long remaining = count;
        do {
            NiPointer<NiRefObject> link(stream.GetObjectFromLinkID());
        } while (--remaining);
    }
    if (unsigned count = stream.GetNumberOfLinkIDs()) {
        unsigned long long remaining = count;
        do {
            NiPointer<NiRefObject> link(stream.GetObjectFromLinkID());
        } while (--remaining);
    }
}
