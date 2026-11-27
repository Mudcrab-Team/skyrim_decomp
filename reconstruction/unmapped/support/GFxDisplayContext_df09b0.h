// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// GFxDisplayContext, GFxDisplayContext::EndClipLayer, GFxDisplayContext::renderConfig, GFxDisplayContext::maskStackSize, GFxDisplayContext::clipDepth: CRASHLOGGER_PDB(59818@2026.10.24)
// GRenderer, GFxRenderConfig, GFxRenderConfig::renderer, GRenderer::DisableMask: GUESS
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
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void DisableMask();
};

struct GFxRenderConfig
{
    std::uint8_t unk00[0x18];
    GRenderer* renderer;
};

class GFxDisplayContext
{
  public:
    void EndClipLayer();

    std::uint8_t unk00[0x68];
    GFxRenderConfig* renderConfig;
    std::uint8_t unk70[0xEC - 0x70];
    std::uint32_t maskStackSize;
    std::uint32_t clipDepth;
};
