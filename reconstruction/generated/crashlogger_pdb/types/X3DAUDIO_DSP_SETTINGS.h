// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: X3DAUDIO_DSP_SETTINGS; size 0x38
#pragma once
struct X3DAUDIO_DSP_SETTINGS {
    float* pMatrixCoefficients;
    float* pDelayTimes;
    unsigned int SrcChannelCount;
    unsigned int DstChannelCount;
    float LPFDirectCoefficient;
    float LPFReverbCoefficient;
    float ReverbLevel;
    float DopplerFactor;
    float EmitterToListenerAngle;
    float EmitterToListenerDistance;
    float EmitterVelocityComponent;
    float ListenerVelocityComponent;
};
static_assert(sizeof(X3DAUDIO_DSP_SETTINGS) == 56, "X3DAUDIO_DSP_SETTINGS layout differs from the PDB");
