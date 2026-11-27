// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Adapted bodies: none
// BGSHavokGeometryAttach, BGSHavokGeometryAttach::AttachPolicy, BGSHavokGeometryAttach::AttachPolicy::Func1_1401A6880: CRASHLOGGER_PDB(59818@2026.10.24)
// HavokAttachTarget, HavokAttachEntry, unk00, unk10, unk18, target, flags38: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class HavokAttachTarget
{
public:
    virtual ~HavokAttachTarget();
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
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Attach(void* a_geom, bool a_flag1, std::uint32_t a_arg3, std::uint32_t a_flags, bool a_flag2);
};

struct HavokAttachEntry
{
    std::uint8_t unk00[0x10];
    void* unk10;
    std::uint8_t unk18[0x30 - 0x18];
    HavokAttachTarget* target;
    std::uint32_t flags38;
};
static_assert(offsetof(HavokAttachEntry, unk10) == 0x10, "HavokAttachEntry::unk10 offset");
static_assert(offsetof(HavokAttachEntry, target) == 0x30, "HavokAttachEntry::target offset");
static_assert(offsetof(HavokAttachEntry, flags38) == 0x38, "HavokAttachEntry::flags38 offset");

class BGSHavokGeometryAttach
{
public:
    class AttachPolicy
    {
    public:
        bool Func1_1401A6880(HavokAttachEntry* a_entry);
    };
};
