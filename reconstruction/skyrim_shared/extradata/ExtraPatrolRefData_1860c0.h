// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPatrolRefData, PatrolRefData, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// ExtraPatrolRefData::patrolData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only
// BSExtraData::next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only
#pragma once

struct PatrolRefData
{
    ~PatrolRefData();
    char unk00[0x28];
};

class BSExtraData
{
public:
    virtual ~BSExtraData() {}

    BSExtraData* next;
};

class ExtraPatrolRefData : public BSExtraData
{
public:
    ExtraPatrolRefData();
    virtual ~ExtraPatrolRefData();  // compared: 0x1860c0

    PatrolRefData* patrolData;
};
