// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UNK_BSImagespaceShaderISTemporalAA; size 0x20
#pragma once

struct BSImagespaceShader;
struct BSImagespaceShaderISTemporalAA;
struct UNK_BSImagespaceShaderISTemporalAA {
    BSImagespaceShaderISTemporalAA* shader;
    BSImagespaceShader* BSImagespaceShaderISTemporalAA_UI;
    BSImagespaceShader* BSImagespaceShaderISTemporalAA_Water;
    bool taaEnabled;
    unsigned char undefined_19[7];
};
static_assert(sizeof(UNK_BSImagespaceShaderISTemporalAA) == 32, "UNK_BSImagespaceShaderISTemporalAA layout differs from the PDB");
