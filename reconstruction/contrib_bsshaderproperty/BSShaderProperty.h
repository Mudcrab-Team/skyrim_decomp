// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14e72c0 BSShaderProperty::CreateClone
// 0x14e74d0 BSShaderProperty::IsEqual
// 0x14e77a0 BSShaderProperty::SetupGeometry
// BSShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSShaderProperty::CreateClone, BSShaderProperty::IsEqual, BSShaderProperty::SetupGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiCloningProcess, BSGeometry: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations only
// Unk_00 through Unk_26 (except CreateClone and IsEqual): GUESS(low); placeholder virtual slots that keep the named slots at slots 0x17, 0x1C and 0x27
#pragma once

class NiObject;
class NiCloningProcess;
class BSGeometry;

class BSShaderProperty
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
    virtual NiObject* CreateClone(NiCloningProcess& a_cloning);  // 17
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual bool IsEqual(NiObject* a_object);  // 1C
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
    virtual bool SetupGeometry(BSGeometry* a_geometry);  // 27
};
