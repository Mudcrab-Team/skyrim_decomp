// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// ProcessLists::SetSystemTimeClock: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// g_systemTimeClock, g_systemTimeClockMax: GUESS(low)
#pragma once

extern float g_systemTimeClock;
extern const float g_systemTimeClockMax;

class ProcessLists
{
public:
    void SetSystemTimeClock(float time);
};
