// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPortalRefData, PortalLinkedRefData, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// ExtraPortalRefData::data, PortalLinkedRefData::linkedRefs, BSExtraData::next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names only
// PortalLinkedRefData::linkedRefs: OBSERVED; two 32-bit handles stand in as unsigned ints
#pragma once

struct PortalLinkedRefData
{
    unsigned int linkedRefs[2];
};

class BSExtraData
{
public:
    virtual ~BSExtraData() {}

    BSExtraData* next;
};

class ExtraPortalRefData : public BSExtraData
{
public:
    ExtraPortalRefData();
    virtual ~ExtraPortalRefData();  // compared: 0x1863d0

    PortalLinkedRefData* data;
};
