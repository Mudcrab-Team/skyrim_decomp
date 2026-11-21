// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ID3D11Buffer; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct ID3D11Buffer {
    ID3D11Buffer* vertexBuffer;
};
static_assert(sizeof(ID3D11Buffer) == 8, "ID3D11Buffer layout differs from the PDB");
