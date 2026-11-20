// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RenderTargetManager; size 0xd44
#pragma once
struct RenderTargetManager {
    unsigned char renderTargetData_raw[3192];
    unsigned char depthStencilTargetData_raw[192];
    unsigned char cubeMapRenderTargetData_raw[12];
};
static_assert(sizeof(RenderTargetManager) == 3396, "RenderTargetManager layout differs from the PDB");
