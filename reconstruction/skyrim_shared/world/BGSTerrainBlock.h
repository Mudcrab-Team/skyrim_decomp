// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and layout labels as marked below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// flags, kHidden: GUESS(low); the flag word at 0xF4 and its low bit agree with the community NiAVObject flag word, but the pointee type is not declared by a community header and stays a labelled standin
// TerrainBlockNode: GUESS(low); the objects behind the two pointers this function marks hidden; only the flag word is read by the compared function
// unknown08, unknown10: GUESS(low); the two scene-node pointers at 0x08 and 0x10 of the block, the only members this function reads
// unknown08 ... unknownF0 (in TerrainBlockNode): GUESS(low); 8-byte members up to the flag word, meaning unrecovered, the function touches none of them
// SetTerrainBlockHidden, ClearTerrainBlockHidden, GetChunkMaterialTexture: GUESS(low); method names inferred from the bodies
// BGSTerrainBlock::~BGSTerrainBlock, TerrainBlockNode::~TerrainBlockNode: GUESS(low); the block and the scene nodes are modelled as polymorphic, so the leading word of each object is its vtable pointer
// unknownF8 ... unknown120 (in TerrainBlockNode): GUESS(low); 8-byte members between the flag word and the shader-property pointer, meaning unrecovered, no compared function reads them
// unknown128: GUESS(low); the pointer at 0x128 of the node, read by 0x511520 and then used only for its virtual GetRTTI and its material pointer at 0x78
// BSLightingShaderProperty: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// material (in BSLightingShaderProperty): COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); BSShaderProperty::material at 0x78, declared here in the derived class because the compared function reaches it through that class
// unknown08 ... unknown70 (in BSLightingShaderProperty): GUESS(low); 8-byte members between the vtable pointer and the material pointer, meaning unrecovered, no compared function reads them
// BSLightingShaderMaterialBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// diffuseTexture, normalTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); BSLightingShaderMaterialBase members at 0x48 and 0x58
// unknown08 ... unknown50 (in BSLightingShaderMaterialBase): GUESS(low); members between the vtable pointer and the two texture pointers, meaning unrecovered, no compared function reads them
// NiRTTI, NiSourceTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRTTI_BSLightingShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the class RTTI object, declared as a data object and resolved by name
// a_useNormal: GUESS(low); the 32-bit argument at 0x511520 selects the 0x58 texture when nonzero and the 0x48 texture when zero
#pragma once

#include <cstdint>
#include <cstddef>

class NiRTTI;
class NiSourceTexture;

// TerrainBlockNode: GUESS(low); a scene node whose low flag bit is the hide bit.
class TerrainBlockNode
{
public:
    virtual ~TerrainBlockNode();  // 00

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70
    std::uint64_t unknown78;  // 78
    std::uint64_t unknown80;  // 80
    std::uint64_t unknown88;  // 88
    std::uint64_t unknown90;  // 90
    std::uint64_t unknown98;  // 98
    std::uint64_t unknownA0;  // A0
    std::uint64_t unknownA8;  // A8
    std::uint64_t unknownB0;  // B0
    std::uint64_t unknownB8;  // B8
    std::uint64_t unknownC0;  // C0
    std::uint64_t unknownC8;  // C8
    std::uint64_t unknownD0;  // D0
    std::uint64_t unknownD8;  // D8
    std::uint64_t unknownE0;  // E0
    std::uint64_t unknownE8;  // E8
    std::uint32_t unknownF0;  // F0

    // flags, kHidden: GUESS(low); type, offset 0xF4 and bit 0 as labelled at the top of this header
    std::uint32_t flags;  // F4
    static constexpr std::uint32_t kHidden = 1u << 0;

    std::uint64_t unknownF8;   // F8
    std::uint64_t unknown100;  // 100
    std::uint64_t unknown108;  // 108
    std::uint64_t unknown110;  // 110
    std::uint64_t unknown118;  // 118
    std::uint64_t unknown120;  // 120

    // unknown128: GUESS(low); pointer at 0x128, see the label at the top of this header
    class BSLightingShaderProperty* unknown128;  // 128
};

static_assert(offsetof(TerrainBlockNode, flags) == 0xF4, "flags offset");
static_assert(offsetof(TerrainBlockNode, unknown128) == 0x128, "unknown128 offset");

// BSLightingShaderProperty: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the
// community header names the class and its material member; the vtable slot before GetRTTI is
// unrecovered, so it stays a labelled placeholder.
class BSLightingShaderProperty
{
public:
    virtual ~BSLightingShaderProperty();            // 00
    virtual void unknownVirtual08();                // 08
    virtual const NiRTTI* GetRTTI() const;          // 10

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70

    // material: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    class BSLightingShaderMaterialBase* material;  // 78
};

static_assert(offsetof(BSLightingShaderProperty, material) == 0x78, "material offset");

// BSLightingShaderMaterialBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the
// community header names the class and the two texture members; the other members are unrecovered.
class BSLightingShaderMaterialBase
{
public:
    virtual ~BSLightingShaderMaterialBase();  // 00

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40

    // diffuseTexture, normalTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    NiSourceTexture* diffuseTexture;  // 48
    std::uint64_t unknown50;          // 50
    NiSourceTexture* normalTexture;   // 58
};

static_assert(offsetof(BSLightingShaderMaterialBase, diffuseTexture) == 0x48, "diffuseTexture offset");
static_assert(offsetof(BSLightingShaderMaterialBase, normalTexture) == 0x58, "normalTexture offset");

// NiRTTI_BSLightingShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
extern const NiRTTI NiRTTI_BSLightingShaderProperty;

class BGSTerrainBlock
{
public:
    virtual ~BGSTerrainBlock();  // 00

    void SetTerrainBlockHidden();

    void ClearTerrainBlockHidden();

    // a_useNormal: GUESS(low); see the label at the top of this header
    NiSourceTexture* GetChunkMaterialTexture(std::int32_t a_useNormal);

    TerrainBlockNode* unknown08;  // 08
    TerrainBlockNode* unknown10;  // 10
};

static_assert(offsetof(BGSTerrainBlock, unknown08) == 0x08, "unknown08 offset");
static_assert(offsetof(BGSTerrainBlock, unknown10) == 0x10, "unknown10 offset");
