// Source exposure: mixed (published inventory and listings from the pinned image; the five new bodies from the pinned image listing).
// Code origin: original forwarding methods inferred from the pinned image.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// Drafted by v-macrev, assisted by claude-haiku-5-5.
// 0x1582070 BSShaderResourceManager::Function1582070
// 0x1582100 BSShaderResourceManager::Function1582100
// 0x1582120 BSShaderResourceManager::Function1582120
// 0x1582140 BSShaderResourceManager::Function1582140
// 0x1582160 BSShaderResourceManager::Function1582160
// 0x1582180 BSShaderResourceManager::Function1582180
// 0x15821a0 BSShaderResourceManager::Function15821a0
// 0x1582250 BSShaderResourceManager::Function1582250
// 0x1582270 BSShaderResourceManager::Function1582270
// 0x1582290 BSShaderResourceManager::Function1582290
// 0x1582550 BSShaderResourceManager::Function1582550
// 0x1582600 BSShaderResourceManager::Function1582600
// 0x1582620 BSShaderResourceManager::Function1582620
// 0x1582640 BSShaderResourceManager::Function1582640
// 0x1582660 BSShaderResourceManager::Function1582660
// 0x15826f0 BSShaderResourceManager::Function15826f0
// 0x1582710 BSShaderResourceManager::Function1582710
// 0x1582730 BSShaderResourceManager::Function1582730
// 0x1582760 BSShaderResourceManager::Function1582760
// 0x15827a0 BSShaderResourceManager::Function15827a0
// 0x1582870 BSShaderResourceManager::Function1582870
// 0x1582890 BSShaderResourceManager::Function1582890
// 0x15828b0 BSShaderResourceManager::Function15828b0
// 0x15828c0 BSShaderResourceManager::Function15828c0
// 0x15829a0 BSShaderResourceManager::Function15829a0
// 0x15829c0 BSShaderResourceManager::Function15829c0
#include "BSShaderResourceManager.h"

// TextureLookupState, g_textureLookupState: STANDIN GUESS(low)
struct TextureLookupState;
extern TextureLookupState g_textureLookupState;

// ShaderResourceState, g_shaderResourceState: STANDIN GUESS(low)
struct ShaderResourceState;
extern ShaderResourceState* g_shaderResourceState;

// g_shaderResourceFlags, g_shaderResourceScale: STANDIN GUESS(low)
extern std::uint32_t g_shaderResourceFlags;
extern float g_shaderResourceScale;

// Function100b530, Function100bac0, Function100c000, Function100c010: GUESS(low)
// Function100bcd0, Function100c850, Function100c090, Function100cf10: GUESS(low)
// Function100cf20, Function10194e0, Function100d250, Function100d1e0: GUESS(low)
// Function100d1f0, Function100d650, Function100d660, Function100f180: GUESS(low)
// Function100f190, Function100d8d0, Function100d950, Function154af80: GUESS(low)
// Function154afb0: GUESS(low)
void Function100b530(TextureLookupState* a_state);
void Function100bac0(TextureLookupState* a_state);
void Function100c000(TextureLookupState* a_state);
void Function100c010(TextureLookupState* a_state);
void Function100bcd0(TextureLookupState* a_state);
void Function100c850(TextureLookupState* a_state);
void Function100c090(TextureLookupState* a_state);
void Function100cf10(TextureLookupState* a_state);
void Function100cf20(TextureLookupState* a_state);
void Function10194e0(void* a_resource, std::uint32_t a_value);
void Function100d250(TextureLookupState* a_state);
void Function100d1e0(TextureLookupState* a_state);
void Function100d1f0(TextureLookupState* a_state);
void Function100d650(TextureLookupState* a_state);
void Function100d660(TextureLookupState* a_state);
void Function100f180(TextureLookupState* a_state);
void Function100f190(TextureLookupState* a_state);
void Function100d8d0(TextureLookupState* a_state);
void Function100d950(TextureLookupState* a_state);
void Function154af80(ShaderResourceState* a_state);
void Function154afb0(ShaderResourceState* a_state);

std::uint32_t BSShaderResourceManager::Function15828b0()
{
    std::uint32_t flags = g_shaderResourceFlags;
    return flags;
}

float BSShaderResourceManager::Function15828c0()
{
    float scale = g_shaderResourceScale;
    return scale;
}

void BSShaderResourceManager::Function1582070()
{
    return Function100b530(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582100()
{
    return Function100bac0(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582120()
{
    return Function100c000(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582140()
{
    return Function100c010(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582160()
{
    return Function100bcd0(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582180()
{
    return Function100c850(&g_textureLookupState);
}

void BSShaderResourceManager::Function15821a0()
{
    return Function100c090(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582250()
{
    return Function100cf10(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582270()
{
    return Function100cf20(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582290(void* a_resource, std::uint8_t a_value)
{
    return Function10194e0(a_resource, a_value);
}

void BSShaderResourceManager::Function1582550()
{
    return Function100d250(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582600()
{
    return Function100d1e0(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582620()
{
    return Function100d1f0(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582640()
{
    return Function100d650(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582660()
{
    return Function100d660(&g_textureLookupState);
}

void BSShaderResourceManager::Function15826f0()
{
    return Function100f180(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582710()
{
    return Function100f190(&g_textureLookupState);
}

void BSShaderResourceManager::Function15827a0()
{
    return Function100d8d0(&g_textureLookupState);
}

void BSShaderResourceManager::Function1582870()
{
    return Function100d950(&g_textureLookupState);
}

void BSShaderResourceManager::Function15829a0()
{
    return Function154af80(g_shaderResourceState);
}

void BSShaderResourceManager::Function15829c0()
{
    return Function154afb0(g_shaderResourceState);
}

void BSShaderResourceManager::Function1582730(LookupSource* a_source, unsigned* a_out1, unsigned* a_out2)
{
    void* data = a_source->data48;
    if (data) {
        Function100f230(gLookupGlobal, data);
    } else {
        *a_out1 = 0;
        *a_out2 = 0;
    }
}

void BSShaderResourceManager::Function1582760(void* a_arg1, void* a_arg2, std::uint64_t a_arg3)
{
    unsigned mask = static_cast<unsigned>((a_arg3 << 2) & 0x3C);
    Function100d6f0(gLookupGlobal, a_arg1, a_arg2, mask, a_arg3, true);
}

void BSShaderResourceManager::Function1582890(void* a1, void* a2, void* a3, void* a4)
{
    Function1019c00(a1, a2, a3, a4);
}
