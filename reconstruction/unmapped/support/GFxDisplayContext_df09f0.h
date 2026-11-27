// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// GFxDisplayContext, GFxDisplayContext::RestoreDisplayState, GFxDisplayContext::cxform, GFxDisplayContext::matrix, GFxDisplayContext::world3D, GFxDisplayContext::perspective3D, GFxDisplayContext::view3D, GFxDisplayContext::has3DWorld, GFxDisplayContext::renderConfig: CRASHLOGGER_PDB(59818@2026.10.24)
// GRenderer, GFxRenderConfig, GFxRenderConfig::renderer, GFxDisplayState, GRenderer::SetPerspective3D, GRenderer::SetView3D, GRenderer::SetWorld3D: GUESS
#pragma once

#include <cstdint>

class GRenderer
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void SetPerspective3D(void* a_mat);
    virtual void SetView3D(void* a_mat);
    virtual void SetWorld3D(void* a_mat);
};

struct GFxRenderConfig
{
    std::uint8_t unk00[0x18];
    GRenderer* renderer;
};

struct GFxDisplayState
{
    void* cxform;
    void* matrix;
    void* world3D;
    void* perspective3D;
    void* view3D;
    bool has3DWorld;
};

class GFxDisplayContext
{
  public:
    void RestoreDisplayState(const GFxDisplayState* a_state);

    void* cxform;
    void* matrix;
    void* world3D;
    void* perspective3D;
    void* view3D;
    bool has3DWorld;
    std::uint8_t unk29[0x68 - 0x29];
    GFxRenderConfig* renderConfig;
    std::uint8_t unk70[0x10];
    void* unk80;
};
