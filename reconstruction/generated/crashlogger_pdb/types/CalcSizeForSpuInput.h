// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CalcSizeForSpuInput; size 0x3
#pragma once
struct CalcSizeForSpuInput {
    bool midphaseAgent3Registered;
    bool isFixedOrKeyframed;
    bool hasDynamicMotionSaved;
};
static_assert(sizeof(CalcSizeForSpuInput) == 3, "CalcSizeForSpuInput layout differs from the PDB");
