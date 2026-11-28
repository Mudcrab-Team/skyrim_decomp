// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0x1572130 ??1BSStreamParserData@@UEAA@XZ
// 0x1572130 BSStreamParserData::~BSStreamParserData
#include "BSStreamParserData_1572130.h"

// The CrashLogger name ctor does not fit this body, which is written as what it does (a guess).
BSStreamParserData::~BSStreamParserData()
{
    delete inner;
    inner = nullptr;
}
