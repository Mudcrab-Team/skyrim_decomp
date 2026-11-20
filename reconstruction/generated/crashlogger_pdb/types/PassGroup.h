// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PassGroup; size 0x30
#pragma once

struct BSRenderPass_87210fc9;
struct PassGroup {
    BSRenderPass_87210fc9* passes[5];
    unsigned int validPassBits;
    unsigned char undefined_2c[4];
};
static_assert(sizeof(PassGroup) == 48, "PassGroup layout differs from the PDB");
