// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// TargetObject1ef8c0, BaseObject1ef8c0, DerivedObject1ef8c0, Unit1ef8c0, GetName1ef8c0, inner, GetDisplayString: GUESS(low)
#pragma once

class TargetObject1ef8c0
{
public:
    virtual void Slot00(); virtual void Slot01(); virtual void Slot02(); virtual void Slot03();
    virtual void Slot04(); virtual void Slot05(); virtual void Slot06(); virtual void Slot07();
    virtual void Slot08(); virtual void Slot09(); virtual void Slot10(); virtual void Slot11();
    virtual void Slot12(); virtual void Slot13(); virtual void Slot14(); virtual void Slot15();
    virtual void Slot16(); virtual void Slot17(); virtual void Slot18(); virtual void Slot19();
    virtual void Slot20(); virtual void Slot21(); virtual void Slot22(); virtual void Slot23();
    virtual void Slot24(); virtual void Slot25(); virtual void Slot26(); virtual void Slot27();
    virtual void Slot28(); virtual void Slot29(); virtual void Slot30(); virtual void Slot31();
    virtual void Slot32(); virtual void Slot33(); virtual void Slot34(); virtual void Slot35();
    virtual void Slot36(); virtual void Slot37(); virtual void Slot38(); virtual void Slot39();
    virtual void Slot40(); virtual void Slot41(); virtual void Slot42(); virtual void Slot43();
    virtual void Slot44(); virtual void Slot45(); virtual void Slot46(); virtual void Slot47();
    virtual void Slot48(); virtual void Slot49();
    virtual const char* GetDisplayString();
};

class BaseObject1ef8c0
{
public:
    virtual ~BaseObject1ef8c0();
};

class DerivedObject1ef8c0 : public BaseObject1ef8c0
{
public:
    TargetObject1ef8c0* inner;  // 08
};

struct Unit1ef8c0
{
    static const char* GetName1ef8c0(BaseObject1ef8c0* a_object);  // compared: 0x1ef8c0
};
