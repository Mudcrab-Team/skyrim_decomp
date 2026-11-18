// Code origin: hand-written from the local listing; names and declarations from the community header named in NiSourceTexture.h.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xef3500 NiSourceTexture::Unk_25
#include "NiSourceTexture.h"

// TextureLookupState, g_textureLookupState, LookupRendererTexture: STANDIN GUESS(low); names invented, the object is at address 0x3331f40 and the function at address 0x100f370
struct TextureLookupState;
extern TextureLookupState g_textureLookupState;
std::uint64_t LookupRendererTexture(TextureLookupState* a_state, BSGraphicsTexture* a_texture);

// Unk_25 is the community name; the community header says it returns 0, the listing consults the renderer texture.
std::uint64_t NiSourceTexture::Unk_25()
{
    if (rendererTexture) {
        return LookupRendererTexture(&g_textureLookupState, rendererTexture);
    }
    return 0;
}
