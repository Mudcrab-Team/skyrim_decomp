// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadInitialData.cpp:75
// 0x620180 CellInitialData::Initialize
// Adapted bodies: CellInitialData::Initialize from the sibling source named above
#include "CellInitialData_620180.h"

void CellInitialData::Initialize(ExteriorCellInitialDataChar* a_data)
{
    iCellX = a_data->cCellX;
    iCellY = a_data->cCellY;
    iDetachTime = a_data->iDetachTime;
    iWorldSpaceID = pSaveLoadGame->WorldspaceFormIDMap.GetFormID(a_data->sWorldSpaceIDIndex);
}
