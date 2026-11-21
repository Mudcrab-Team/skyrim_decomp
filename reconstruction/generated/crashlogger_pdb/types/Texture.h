// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Texture; size 0x28
#pragma once

struct ID3D11Resource;
struct ID3D11ShaderResourceView;
struct ID3D11UnorderedAccessView;
struct Texture {
    ID3D11Resource* texture;
    ID3D11UnorderedAccessView* UAV;
    ID3D11ShaderResourceView* resourceView;
    unsigned short height;
    unsigned short width;
    unsigned char mips;
    unsigned char format;
    unsigned short unk1E;
    unsigned int refCount;
    unsigned int pad24;
};
static_assert(sizeof(Texture) == 40, "Texture layout differs from the PDB");
