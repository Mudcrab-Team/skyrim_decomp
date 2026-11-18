// BGSPackageDataLocation: GUESS(low) STANDIN
/*
 * BGSPackageDataLocation: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x44e080 24 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis, community-headers.
 * Drafted by: gpt-6.1-sol (Terra declaration draft adapted for secondary virtual interface).
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); unverified against this build.
 * No external body adapted. Partial interfaces are stand-ins.
 * Unk_0C returns bool here as an inferred signature correction to the community void declaration.
 * The method overrides the IPackageData secondary interface; this is not a complete-object constructor.
 * The target entry is the secondary virtual implementation, not an adjustor thunk.
 */
#pragma once

/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#include <cstdint>
// IPackageData, IAIWorldLocationHandle, IPackageDataAIWorldLocationHandle, BGSNamedPackageData, BGSPackageDataPointerTemplate, BGSPackageDataLocation, PackageLocation: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSPackageDataLocation::Unk_0C, PackageLocation::LocationType: GUESS(low) STANDIN
class BSFixedString; class BSString; class TESFile; class BGSLoadFormBuffer; class IAIWorldLocation; class TESObjectREFR; struct AIWorldLocationContext;
class PackageLocation { public: int LocationType(); };
class IPackageData { public:
    virtual ~IPackageData(); virtual void InitPackage() = 0; virtual void LoadPackage(TESFile*) = 0; virtual void Assign(IPackageData*) = 0; virtual bool IsNotEqual(IPackageData*) const = 0;
    virtual void Unk_05() = 0; virtual void Unk_06(); virtual void Unk_07(); virtual void LoadBuffer(BGSLoadFormBuffer*); virtual void Unk_09(); virtual bool GetDataAsString(BSString*) const = 0;
    virtual const BSFixedString& GetTypeName() const = 0; virtual bool Unk_0C();
};
class IAIWorldLocationHandle { public: virtual ~IAIWorldLocationHandle(); virtual const IAIWorldLocation* AllocateLocation(AIWorldLocationContext*) = 0; virtual PackageLocation* GetAsPackageLocation(); virtual bool IsRefAtLocation(AIWorldLocationContext*, TESObjectREFR*) = 0; };
class IPackageDataAIWorldLocationHandle : public IAIWorldLocationHandle, public IPackageData { public: ~IPackageDataAIWorldLocationHandle() override; };
template<class Parent> class BGSNamedPackageData : public Parent { public:
    union Data { bool b; std::uint32_t i; float f; void* p; };
    void InitPackage() override; void LoadPackage(TESFile*) override; void Assign(IPackageData*) override; bool IsNotEqual(IPackageData*) const override;
    Data data;
};
template<class Parent, class Pointer> class BGSPackageDataPointerTemplate : public BGSNamedPackageData<Parent> { public:
    virtual ~BGSPackageDataPointerTemplate(); void Unk_05() override; const BSFixedString& GetTypeName() const override; virtual void LoadPointer(TESFile*) = 0; Pointer* pointer;
};
class BGSPackageDataLocation : public BGSPackageDataPointerTemplate<IPackageDataAIWorldLocationHandle, PackageLocation> { public: ~BGSPackageDataLocation() override; bool Unk_0C() override; };
static_assert(sizeof(BGSPackageDataLocation) == 0x20, "BGSPackageDataLocation size");
// IPackageData::InitPackage, IPackageData::LoadPackage, IPackageData::Assign, IPackageData::IsNotEqual, IPackageData::Unk_05, IPackageData::Unk_06, IPackageData::Unk_07, IPackageData::LoadBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// IPackageData::Unk_09, IPackageData::GetDataAsString, IPackageData::GetTypeName, IPackageData::Unk_0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// IAIWorldLocationHandle::AllocateLocation, IAIWorldLocationHandle::GetAsPackageLocation, IAIWorldLocationHandle::IsRefAtLocation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSNamedPackageData::Data, BGSNamedPackageData::InitPackage, BGSNamedPackageData::LoadPackage, BGSNamedPackageData::Assign, BGSNamedPackageData::IsNotEqual, BGSNamedPackageData::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSPackageDataPointerTemplate::Unk_05, BGSPackageDataPointerTemplate::GetTypeName, BGSPackageDataPointerTemplate::LoadPointer, BGSPackageDataPointerTemplate::pointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSFixedString, BSString, TESFile, BGSLoadFormBuffer, IAIWorldLocation, TESObjectREFR, AIWorldLocationContext: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
