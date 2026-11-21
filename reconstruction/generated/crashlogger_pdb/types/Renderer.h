// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Renderer; size 0x21c8
#pragma once

#include "DXGI_RATIONAL.h"
struct ID3D11Device;
struct ID3D11DeviceContext;
struct Renderer {
    unsigned long long unk000;
    void* unk008;
    unsigned int uiAdapter;
    DXGI_RATIONAL desiredRefreshRate;
    DXGI_RATIONAL actualRefreshRate;
    unsigned char scaleMode_raw[4];
    unsigned char scanlineOrdering_raw[4];
    unsigned int isNotWindowed;
    bool fullScreen;
    bool borderlessDisplay;
    bool readOnlyDepth;
    bool instantiated;
    bool requestedWindowSizeChange;
    bool unk25;
    unsigned char undefined_36[2];
    unsigned int newWidth;
    unsigned int newHeight;
    unsigned int presentInterval;
    unsigned char undefined_44[4];
    ID3D11Device* forwarder;
    ID3D11DeviceContext* context;
    unsigned char renderWindows_raw[2560];
    unsigned char renderTargets_raw[6000];
};
static_assert(sizeof(Renderer) == 8648, "Renderer layout differs from the PDB");
