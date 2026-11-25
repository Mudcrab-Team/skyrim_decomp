// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPatrolRefData, PatrolRefData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) CRASHLOGGER_PDB(59818@2026.10.24)
// ExtraPatrolRefData::patrolData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only
// ExtraPatrolRefData::ClearPatrolData: GUESS(low)
#pragma once

struct PatrolRefData
{
    ~PatrolRefData();
    char unk00[0x28];
};

class ExtraPatrolRefData
{
public:
    void ClearPatrolData();  // compared: 0x186120

    char unk00[0x10];
    PatrolRefData* patrolData;
};
