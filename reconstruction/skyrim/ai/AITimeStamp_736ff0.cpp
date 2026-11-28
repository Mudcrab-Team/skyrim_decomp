// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// AITimeStamp, AITimeStamp::LoadGame: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x736ff0 AITimeStamp::LoadGame
#include "AITimeStamp_736ff0.h"

// Loads the serialized AI timestamp and shifts finite timestamps by current AI time.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void AITimeStamp::LoadGame(BGSLoadGameBuffer* a_buf)
{
    a_buf->LoadDataEndian(&timeStamp, 4, 4);
    if (timeStamp < 3.402823466e+38f && timeStamp > -3.402823466e+38f)
    {
        timeStamp += gCurrentAITime;
    }
}
