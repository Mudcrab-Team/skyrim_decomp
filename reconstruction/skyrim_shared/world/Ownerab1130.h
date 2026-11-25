// Source exposure: mixed
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainManager.cpp:6
// Code origin: original; the pinned image listing and community declarations only Stamped as a twin of matched 0x5166e0 (skyrim_shared/world/BGSTerrainManager): source copied, names replaced by placeholders.
// Functionab1130, Ownerab1130: GUESS(low) STANDIN
// rootNode, Function516740, Function516750: GUESS(low) STANDIN
#pragma once
#include "BGSTerrainManager.h"

class Ownerab1130
{
public:
    static NiNode* roots[4];
    static NiNode* GetLODLandRootForLevel(unsigned level);
    void* Functionab1130(const void* a_point, bool a_flag);
    static bool Function516c20();
    void Function516740(void* a_block);
    void Function516750(void* a_value);

    NiTexture* GetDiffuseTextureForPoint(const NiPoint3& a_point);
    NiTexture* GetNormalTextureForPoint(const NiPoint3& a_point);
    static void Function516b80();
    static void Function516bc0();

    std::uint8_t unknown00[0x20];
    BGSTerrainNode* rootNode;
};
