// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: X3DAUDIO_EMITTER; size 0x80
#pragma once

#include "D3DVECTOR.h"
struct X3DAUDIO_CONE;
struct X3DAUDIO_DISTANCE_CURVE;
struct X3DAUDIO_EMITTER {
    X3DAUDIO_CONE* pCone;
    D3DVECTOR OrientFront;
    D3DVECTOR OrientTop;
    D3DVECTOR Position;
    D3DVECTOR Velocity;
    float InnerRadius;
    float InnerRadiusAngle;
    unsigned int ChannelCount;
    float ChannelRadius;
    float* pChannelAzimuths;
    X3DAUDIO_DISTANCE_CURVE* pVolumeCurve;
    X3DAUDIO_DISTANCE_CURVE* pLFECurve;
    X3DAUDIO_DISTANCE_CURVE* pLPFDirectCurve;
    X3DAUDIO_DISTANCE_CURVE* pLPFReverbCurve;
    X3DAUDIO_DISTANCE_CURVE* pReverbCurve;
    float CurveDistanceScalar;
    float DopplerScalar;
};
static_assert(sizeof(X3DAUDIO_EMITTER) == 128, "X3DAUDIO_EMITTER layout differs from the PDB");
