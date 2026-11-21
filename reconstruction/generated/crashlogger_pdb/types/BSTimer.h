// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTimer; size 0x40
#pragma once
struct BSTimer {
    float* smoothingBuffer;
    long long qpcBaseline;
    float clamp;
    float clampRemainder;
    float delta;
    float realTimeDelta;
    unsigned int smoothedRunTimeMS;
    unsigned int runTimeMS;
    unsigned int runTimeMSBaseline;
    unsigned int pausedSmoothedRunTimeOffset;
    unsigned int pausedRunTimeOffset;
    unsigned int pauseCount;
    unsigned char smoothingSampleCount;
    unsigned char smoothingBufferIndex;
    bool useGlobalTimeMultiplierTarget;
    unsigned char pad3B;
    unsigned int pad3C;
};
static_assert(sizeof(BSTimer) == 64, "BSTimer layout differs from the PDB");
