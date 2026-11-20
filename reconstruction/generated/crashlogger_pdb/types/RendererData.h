// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RendererData; size 0x28
#pragma once

struct ID3D11ShaderResourceView;
struct ID3D11Texture2D;
struct RendererData {
    ID3D11Texture2D* texture;
    unsigned long long unk08;
    ID3D11ShaderResourceView* resourceView;
    unsigned short width;
    unsigned short height;
    unsigned char unk1C;
    unsigned char unk1D;
    unsigned short unk1E;
    unsigned int unk20;
    unsigned int unk24;
};
static_assert(sizeof(RendererData) == 40, "RendererData layout differs from the PDB");
