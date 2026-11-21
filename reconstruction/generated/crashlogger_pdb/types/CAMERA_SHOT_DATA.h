// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CAMERA_SHOT_DATA; size 0x2c
#pragma once

#include "CAM_ACTION.h"
#include "CAM_OBJECT.h"
#include "Flag_a4a94b8a.h"
struct CAMERA_SHOT_DATA {
    CAM_ACTION cameraAction;
    CAM_OBJECT location;
    CAM_OBJECT target;
    Flag_a4a94b8a flags;
    float playerTimeMult;
    float targetTimeMult;
    float globalTimeMult;
    float maxTime;
    float minTime;
    float targetPercentBetweenActors;
    float nearTargetDistance;
};
static_assert(sizeof(CAMERA_SHOT_DATA) == 44, "CAMERA_SHOT_DATA layout differs from the PDB");
