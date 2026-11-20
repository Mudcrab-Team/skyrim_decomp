// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: VertexBuffer; size 0x18
#pragma once

struct ID3D11Buffer_63d37e24;
struct VertexBuffer {
    ID3D11Buffer_63d37e24* buffer;
    void* m_data;
    unsigned long long byteWidth;
};
static_assert(sizeof(VertexBuffer) == 24, "VertexBuffer layout differs from the PDB");
