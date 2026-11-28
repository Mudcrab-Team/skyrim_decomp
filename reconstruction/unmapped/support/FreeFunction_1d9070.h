// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Component1d9070, FormBase1d9070, DerivedFormA1d9070, DerivedFormB1d9070, HasExtendedComponent1d9070, GetComponentResult1d9070, unk08, formType, unk1B, unk30, Slot0, Slot1, Slot2, Slot3, QueryValue: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Component1d9070
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void* QueryValue();
};

class FormBase1d9070
{
public:
    virtual ~FormBase1d9070();

    std::uint8_t unk08[0x12];  // 08
    std::uint8_t formType;     // 1A
    std::uint8_t unk1B[0x15];  // 1B
};
static_assert(sizeof(FormBase1d9070) == 0x30, "FormBase1d9070 size");
static_assert(offsetof(FormBase1d9070, formType) == 0x1A, "FormBase1d9070::formType offset");

class DerivedFormA1d9070 : public FormBase1d9070, public Component1d9070
{
};

class DerivedFormB1d9070 : public FormBase1d9070
{
public:
    std::uint8_t unk30[0x70];  // 30
    Component1d9070 component; // A0
};
static_assert(offsetof(DerivedFormB1d9070, component) == 0xA0, "DerivedFormB1d9070::component offset");

bool HasExtendedComponent1d9070(FormBase1d9070* a_form);
void* GetComponentResult1d9070(FormBase1d9070* a_form);  // compared: 0x1d9070
