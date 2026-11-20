// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RendererWindow; size 0x50
#pragma once

struct HWND;
struct ID3D11RenderTargetView1;
struct ID3D11ShaderResourceView1;
struct IDXGISwapChain;
struct RendererWindow {
    HWND* hWnd;
    int windowX;
    int windowY;
    int windowWidth;
    int windowHeight;
    IDXGISwapChain* swapChain;
    unsigned char swapChainRenderTarget_raw[4];
    unsigned int unk24;
    unsigned long long unk28;
    ID3D11RenderTargetView1* renderView;
    ID3D11ShaderResourceView1* resourceView;
    unsigned long long unk40;
    unsigned long long unk48;
};
static_assert(sizeof(RendererWindow) == 80, "RendererWindow layout differs from the PDB");
