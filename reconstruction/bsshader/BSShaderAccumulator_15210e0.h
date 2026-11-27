// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSShaderAccumulator::ClearSunOcclusionTests, SunOcclusionTest and BSShaderAccumulator layouts: CRASHLOGGER_PDB(59818@2026.10.24)
// QueryRenderer, ReleaseQuery and queryRenderer: GUESS(low) STANDIN
#pragma once

#include "generated/crashlogger_pdb/types/SunOcclusionTest.h"

struct QueryRenderer {
    void ReleaseQuery(void* query);
};
extern QueryRenderer queryRenderer;
struct BSShaderAccumulator {
    unsigned char unknown00[0x64];
    bool waitingForSunQuery;
    unsigned char unknown65[11];
    SunOcclusionTest sunOcclusionTests[3];
    void ClearSunOcclusionTests();
};
