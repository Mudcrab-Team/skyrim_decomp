// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original member teardown from the assigned local pack; community declarations only.
// ExtraSeenData, SeenData, seenData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraSeenData::~ExtraSeenData: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x156510 ExtraSeenData::~ExtraSeenData
#include "ExtraSeenData_156510.h"

ExtraSeenData::~ExtraSeenData()
{
    delete seenData;
}
