// Source exposure: mixed (community and sibling declarations, pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiGeometry, UpdateWorldBound: CRASHLOGGER_PDB(59818@2026.10.24) COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBound, NiPoint3, NiMatrix3, NiTransform, world, worldBound, flags, center, radius, rotate, translate, scale, entry, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiSkinInstance, NiGeometryData, m_spSkinInstance, m_spModelData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; pointer order follows this body
// kFixedBound, kRenderUse: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TransformBoundToWorld: CRASHLOGGER_PDB(59818@2026.10.24)
// ComputeBound, TestBit, unk00, reserved08, unkB0, unkF8, unk01, unk02, unk03, unk04, unk05, unk06, unk07, unk08, unk09, unk0A, unk0B, unk0C, unk0D, unk0E, unk0F, unk10, unk11, unk12, unk13, unk14, unk15, unk16, unk17, unk18, unk19, unk1A, unk1B, unk1C, unk1D, unk1E, unk1F, unk20, unk21, unk22, unk23, unk24, unk25, unk26, unk27, unk28, unk29, unk2A, unk2B, unk2C, unk2D, unk2E: GUESS(low)
// ZERO, TransformPoint: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// Adapted bodies: NiGeometry::UpdateWorldBound follows momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nigeometry.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nigeometry.cpp:103
#pragma once

#include <cstdint>

class NiPoint3
{
public:
    static const NiPoint3 ZERO;

    float x;
    float y;
    float z;
};

class NiMatrix3
{
public:
    float entry[3][3];
};

class NiTransform
{
public:
    NiMatrix3 rotate;
    NiPoint3 translate;
    float scale;
};

class NiBound
{
public:
    void TransformPoint(const NiPoint3& point, const NiTransform& transform)
    {
        const float scale = transform.scale;
        const float y = point.y;
        const float x = point.x;
        const float z = point.z;
        const auto& m = transform.rotate.entry;
        const float rowZ = m[2][1] * y + m[2][0] * x + m[2][2] * z;
        const float rowX = m[0][1] * y + m[0][0] * x + m[0][2] * z;
        const float rowY = m[1][1] * y + m[1][0] * x + m[1][2] * z;
        center.z = rowZ * scale;
        center.x = rowX * scale;
        center.y = rowY * scale;
        center.x += transform.translate.x;
        center.y += transform.translate.y;
        center.z += transform.translate.z;
    }

    void TransformBoundToWorld(const NiBound& modelBound, const NiTransform& transform);

    NiPoint3 center;
    float radius;
};

class NiSkinInstance
{
public:
    void ComputeBound(NiBound& bound);
};

class NiGeometryData
{
public:
    std::uint64_t unk00[3];
    NiBound bound;
};

class NiGeometry
{
public:
    virtual ~NiGeometry();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual void unk26();
    virtual void unk27();
    virtual void unk28();
    virtual void unk29();
    virtual void unk2A();
    virtual void unk2B();
    virtual void unk2C();
    virtual void unk2D();
    virtual void unk2E();
    virtual void UpdateWorldBound();

private:
    enum Flag : std::uint32_t
    {
        kFixedBound = 1U << 13,
        kRenderUse = 1U << 22
    };

    std::uint32_t reserved08[(0x7C - 8) / 4];
    NiTransform world;
    std::uint32_t unkB0[0x34 / 4];
    NiBound worldBound;
    std::uint32_t flags;
    std::uint64_t unkF8[5];
    NiGeometryData* m_spModelData;
    NiSkinInstance* m_spSkinInstance;
};
