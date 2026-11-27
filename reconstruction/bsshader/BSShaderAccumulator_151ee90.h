// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSShaderAccumulator layout, FinishAccumulatingDispatch, FinishAccumulatingCommonPasses and BSShaderManager::SetRenderMode: CRASHLOGGER_PDB(59818@2026.10.24)
// FinishPasses and finishPasses: GUESS(low) STANDIN
#pragma once

struct BSShaderManager {
    static void SetRenderMode(int mode);
};
struct BSShaderAccumulator {
    unsigned char unknown00[0x150];
    int renderMode;
    void FinishAccumulatingDispatch(int flags);
    void FinishAccumulatingCommonPasses(int flags);
};
using FinishPasses = void (*)(BSShaderAccumulator*, int);
extern FinishPasses finishPasses[];
