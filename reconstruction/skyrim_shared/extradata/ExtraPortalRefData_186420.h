// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPortalRefData, PortalLinkedRefData, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// ExtraPortalRefData::IsNotEqual, ExtraPortalRefData::data, PortalLinkedRefData::linkedRefs: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; handles stand in as unsigned ints
// ExtraPortalRefData::unk00: GUESS(low); covers the vtable pointer and the base link
#pragma once

struct PortalLinkedRefData
{
    unsigned int linkedRefs[2];
};

class BSExtraData;

class ExtraPortalRefData
{
public:
    bool IsNotEqual(const BSExtraData* a_rhs) const;  // compared: 0x186420

    char unk00[0x10];
    PortalLinkedRefData* data;
};
