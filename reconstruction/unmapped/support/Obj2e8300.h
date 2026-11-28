// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// ContainerComp2e8300, BaseForm2e8300, ContainerForm2e8300, NpcForm2e8300, Obj2e8300, Obj2e8300::ForwardItem: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ContainerComp2e8300
{
    std::uint64_t unk00;  // 0x00
};

struct BaseForm2e8300
{
    std::uint64_t unk00[3];   // 0x00
    std::uint16_t unk18;      // 0x18
    std::uint8_t m_formType;  // 0x1A
    std::uint8_t unk1B[5];    // 0x1B
    std::uint64_t unk20[2];   // 0x20
};
static_assert(offsetof(BaseForm2e8300, m_formType) == 0x1A, "m_formType offset");
static_assert(sizeof(BaseForm2e8300) == 0x30, "BaseForm2e8300 size");

struct ContainerForm2e8300 : public BaseForm2e8300, public ContainerComp2e8300
{
};

struct NpcForm2e8300 : public BaseForm2e8300
{
    std::uint64_t unk30[11];  // 0x30
    ContainerComp2e8300 m_container;  // 0x88
};
static_assert(offsetof(NpcForm2e8300, m_container) == 0x88, "m_container offset");

class Obj2e8300
{
public:
    virtual ~Obj2e8300();
    virtual void V01(); virtual void V02(); virtual void V03(); virtual void V04();
    virtual void V05(); virtual void V06(); virtual void V07(); virtual void V08();
    virtual void V09(); virtual void V0A(); virtual void V0B(); virtual void V0C();
    virtual void V0D(); virtual void V0E(); virtual void V0F(); virtual void V10();
    virtual void V11(); virtual void V12(); virtual void V13(); virtual void V14();
    virtual void V15(); virtual void V16(); virtual void V17(); virtual void V18();
    virtual void V19(); virtual void V1A(); virtual void V1B(); virtual void V1C();
    virtual void V1D(); virtual void V1E(); virtual void V1F(); virtual void V20();
    virtual void V21(); virtual void V22(); virtual void V23(); virtual void V24();
    virtual void V25(); virtual void V26(); virtual void V27(); virtual void V28();
    virtual void V29(); virtual void V2A(); virtual void V2B(); virtual void V2C();
    virtual void V2D(); virtual void V2E(); virtual void V2F(); virtual void V30();
    virtual void V31(); virtual void V32(); virtual void V33(); virtual void V34();
    virtual void V35(); virtual void V36(); virtual void V37(); virtual void V38();
    virtual void V39(); virtual void V3A(); virtual void V3B(); virtual void V3C();
    virtual void V3D(); virtual void V3E(); virtual void V3F(); virtual void V40();
    virtual void V41(); virtual void V42(); virtual void V43(); virtual void V44();
    virtual void V45(); virtual void V46(); virtual void V47(); virtual void V48();
    virtual void V49(); virtual void V4A(); virtual void V4B(); virtual void V4C();
    virtual void V4D(); virtual void V4E(); virtual void V4F(); virtual void V50();
    virtual void V51(); virtual void V52(); virtual void V53(); virtual void V54();
    virtual void V55(); virtual void V56(); virtual void V57(); virtual void V58();
    virtual void V59(); virtual void V5A(); virtual void V5B(); virtual void V5C();
    virtual void V5D(); virtual void V5E(); virtual void V5F(); virtual void V60();
    virtual void V61(); virtual void V62(); virtual void V63(); virtual void V64();
    virtual void V65(); virtual void V66(); virtual void V67(); virtual void V68();
    virtual void V69(); virtual void V6A(); virtual void V6B(); virtual void V6C();
    virtual void V6D(); virtual void V6E(); virtual void V6F(); virtual void V70();
    virtual void V71(); virtual void V72(); virtual void V73(); virtual void V74();
    virtual void V75(); virtual void V76(); virtual void V77(); virtual void V78();
    virtual void V79(); virtual void V7A(); virtual void V7B(); virtual void V7C();
    virtual void V7D(); virtual void V7E(); virtual void V7F(); virtual void V80();
    virtual void V81(); virtual void V82(); virtual void V83(); virtual void V84();
    virtual void V85(); virtual void V86(); virtual void V87(); virtual void V88();
    virtual void V89(); virtual void V8A(); virtual void V8B(); virtual void V8C();
    virtual void V8D(); virtual void V8E(); virtual void V8F(); virtual void V90();
    virtual void V91(); virtual void V92(); virtual void V93(); virtual void V94();
    virtual void V95(); virtual void V96(); virtual void V97(); virtual void V98();
    virtual void V99(); virtual void V9A(); virtual void V9B(); virtual void V9C();
    virtual void V9D(); virtual void V9E(); virtual void V9F(); virtual void VA0();
    virtual void OnForward(void* a_changes, void* a_item, std::uint32_t a_count, void* a_extra);

    void* GetChanges();
    bool ForwardItem(void* a_item, std::uint32_t a_count, void* a_extra);

    std::uint64_t unk08[7];   // 0x08
    BaseForm2e8300* m_base;   // 0x40
};
static_assert(offsetof(Obj2e8300, m_base) == 0x40, "m_base offset");
