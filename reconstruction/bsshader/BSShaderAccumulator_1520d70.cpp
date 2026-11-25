// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// BSShaderAccumulator, batchRenderer, BSBatchRenderer: CRASHLOGGER_PDB(59818@2026.10.24)
// FinishAlphaGroup: GUESS(low)
// StopGroupingAlphas, GeometryGroup: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// 0x1520d70 BSShaderAccumulator::StopGroupingAlphas
// CI hash: 0x1520d70 ?StopGroupingAlphas@BSShaderAccumulator@@QEAAXPEAUGeometryGroup@BSBatchRenderer@@@Z
#include "BSShaderAccumulator_1520d70.h"

void BSShaderAccumulator::StopGroupingAlphas(BSBatchRenderer::GeometryGroup* group)
{
    batchRenderer->FinishAlphaGroup(group);
}
