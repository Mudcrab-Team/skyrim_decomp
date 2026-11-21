// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: written for this reconstruction from the pinned image listing at 0xefc400 and from
// the declarations in NiAVObject.h and NiObjectNET.h; no community body is copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the write path only
// _absoluteCurrentPos, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// WriteBytes: GUESS(low); NG's binary_write is a protected member, called here through the stream
// vftable, unk10: GUESS(low); the vftable and the read function pointer, not used here
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slots 00 to 0C and oStr
// SaveLinkID, oStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_01 to Unk_06: GUESS(low); placeholders for the stream's loading and saving slots so SaveLinkID lands on slot 0C
// Unk_07, iStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the unnamed slot and the input stream pointer
// unknown08 to unknown290: GUESS(low); the bytes between the vftable and iStr. Their meanings are
// not recovered and the compared code reads none of them; each 8-byte member keeps its real offset.
// 0xefc400 BSGeometry::SaveBinary
// 0xefc6e0 BSGeometry::UpdateDownwardPass
// 0xefc720 BSGeometry::UpdateSelectedDownwardPass
// 0xefc680 BSGeometry::SetSelectiveUpdateFlags
// 0xefc380 BSGeometry::RegisterStreamables
#include "BSGeometry.h"

#include <cstdint>
#include <cstddef>

class NiBinaryStream
{
public:
    using WriteFn = std::uint32_t(NiBinaryStream* a_this, const void* a_buffer, std::uint32_t a_bytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    std::uint32_t WriteBytes(const void* a_buffer, std::uint32_t a_totalBytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents = 1)
    {
        std::uint32_t written = _writeFn(this, a_buffer, a_totalBytes, a_componentSizes, a_numComponents);
        _absoluteCurrentPos += written;
        return written;
    }

    void*         vftable;              // 00
    std::uint32_t _absoluteCurrentPos;  // 08
    std::uint32_t _unknown0C;           // 0C
    void*         unk10;                // 10
    WriteFn*      _writeFn;             // 18
};
static_assert(sizeof(NiBinaryStream) == 0x20, "NiBinaryStream size");

class NiStream
{
public:
    virtual ~NiStream();                                                  // 00
    virtual void Unk_01();                                                // 01
    virtual void Unk_02();                                                // 02
    virtual void Unk_03();                                                // 03
    virtual void Unk_04();                                                // 04
    virtual void Unk_05();                                                // 05
    virtual void Unk_06();                                                // 06
    virtual void Unk_07();                                                // 07
    virtual bool RegisterFixedString(const BSFixedString& a_fixedString);  // 08
    virtual bool RegisterSaveObject(NiObject* a_object);                  // 09
    virtual bool ChangeObject(NiObject* a_object);                        // 0A
    virtual std::uint32_t GetLinkIDFromObject(const NiObject* a_object);  // 0B
    virtual void SaveLinkID(const NiObject* a_object);                    // 0C

    std::uint64_t    unknown08;     // 008
    std::uint64_t    unknown10;     // 010
    std::uint64_t    unknown18;     // 018
    std::uint64_t    unknown20;     // 020
    std::uint64_t    unknown28;     // 028
    std::uint64_t    unknown30;     // 030
    std::uint64_t    unknown38;     // 038
    std::uint64_t    unknown40;     // 040
    std::uint64_t    unknown48;     // 048
    std::uint64_t    unknown50;     // 050
    std::uint64_t    unknown58;     // 058
    std::uint64_t    unknown60;     // 060
    std::uint64_t    unknown68;     // 068
    std::uint64_t    unknown70;     // 070
    std::uint64_t    unknown78;     // 078
    std::uint64_t    unknown80;     // 080
    std::uint64_t    unknown88;     // 088
    std::uint64_t    unknown90;     // 090
    std::uint64_t    unknown98;     // 098
    std::uint64_t    unknownA0;     // 0A0
    std::uint64_t    unknownA8;     // 0A8
    std::uint64_t    unknownB0;     // 0B0
    std::uint64_t    unknownB8;     // 0B8
    std::uint64_t    unknownC0;     // 0C0
    std::uint64_t    unknownC8;     // 0C8
    std::uint64_t    unknownD0;     // 0D0
    std::uint64_t    unknownD8;     // 0D8
    std::uint64_t    unknownE0;     // 0E0
    std::uint64_t    unknownE8;     // 0E8
    std::uint64_t    unknownF0;     // 0F0
    std::uint64_t    unknownF8;     // 0F8
    std::uint64_t    unknown100;    // 100
    std::uint64_t    unknown108;    // 108
    std::uint64_t    unknown110;    // 110
    std::uint64_t    unknown118;    // 118
    std::uint64_t    unknown120;    // 120
    std::uint64_t    unknown128;    // 128
    std::uint64_t    unknown130;    // 130
    std::uint64_t    unknown138;    // 138
    std::uint64_t    unknown140;    // 140
    std::uint64_t    unknown148;    // 148
    std::uint64_t    unknown150;    // 150
    std::uint64_t    unknown158;    // 158
    std::uint64_t    unknown160;    // 160
    std::uint64_t    unknown168;    // 168
    std::uint64_t    unknown170;    // 170
    std::uint64_t    unknown178;    // 178
    std::uint64_t    unknown180;    // 180
    std::uint64_t    unknown188;    // 188
    std::uint64_t    unknown190;    // 190
    std::uint64_t    unknown198;    // 198
    std::uint64_t    unknown1A0;    // 1A0
    std::uint64_t    unknown1A8;    // 1A8
    std::uint64_t    unknown1B0;    // 1B0
    std::uint64_t    unknown1B8;    // 1B8
    std::uint64_t    unknown1C0;    // 1C0
    std::uint64_t    unknown1C8;    // 1C8
    std::uint64_t    unknown1D0;    // 1D0
    std::uint64_t    unknown1D8;    // 1D8
    std::uint64_t    unknown1E0;    // 1E0
    std::uint64_t    unknown1E8;    // 1E8
    std::uint64_t    unknown1F0;    // 1F0
    std::uint64_t    unknown1F8;    // 1F8
    std::uint64_t    unknown200;    // 200
    std::uint64_t    unknown208;    // 208
    std::uint64_t    unknown210;    // 210
    std::uint64_t    unknown218;    // 218
    std::uint64_t    unknown220;    // 220
    std::uint64_t    unknown228;    // 228
    std::uint64_t    unknown230;    // 230
    std::uint64_t    unknown238;    // 238
    std::uint64_t    unknown240;    // 240
    std::uint64_t    unknown248;    // 248
    std::uint64_t    unknown250;    // 250
    std::uint64_t    unknown258;    // 258
    std::uint64_t    unknown260;    // 260
    std::uint64_t    unknown268;    // 268
    std::uint64_t    unknown270;    // 270
    std::uint64_t    unknown278;    // 278
    std::uint64_t    unknown280;    // 280
    std::uint64_t    unknown288;    // 288
    std::uint64_t    unknown290;    // 290
    NiBinaryStream* iStr;          // 298
    NiBinaryStream* oStr;          // 2A0
};
static_assert(offsetof(NiStream, oStr) == 0x2A0, "NiStream oStr");

// FieldAt: GUESS(low); typed access at a fixed byte offset inside the opaque base layout.
template <class T>
static inline T& FieldAt(void* a_base, std::size_t a_offset)
{
    return *reinterpret_cast<T*>(static_cast<std::uint8_t*>(a_base) + a_offset);
}

// Body done: RVA 0xefc400, 145 bytes, BSGeometry::SaveBinary.
void BSGeometry::SaveBinary(NiStream& a_stream)
{
    BaseSaveBinary(a_stream);
    data110.SaveBinaryFields(a_stream);
    a_stream.SaveLinkID(skinInstance);
    a_stream.SaveLinkID(effect);
    a_stream.SaveLinkID(property);
    std::uint32_t componentSize = sizeof(vertexDesc);
    a_stream.oStr->WriteBytes(&vertexDesc, sizeof(vertexDesc), &componentSize, 1);
}

// Body done: RVA 0xefc6e0, 49 bytes, BSGeometry::UpdateDownwardPass.
void BSGeometry::UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
    BaseUpdateDownwardPass(a_data, a_arg2);
    if ((FieldAt<std::uint8_t>(&a_data, 0x4) & 1) != 0) {
        UpdateBoundFromFlags(a_data);
    }
}

// Body done: RVA 0xefc720, 56 bytes, BSGeometry::UpdateSelectedDownwardPass.
void BSGeometry::UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
    BaseUpdateSelectedDownwardPass(a_data, a_arg2);
    if ((static_cast<std::uint8_t>(FieldAt<std::uint32_t>(this, 0xf4) >> 3) & 1) != 0) {
        UpdateBoundFromFlags(a_data);
    }
}

// Body done: RVA 0xefc680, 75 bytes, BSGeometry::SetSelectiveUpdateFlags.
void BSGeometry::SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid)
{
    BaseSetSelectiveUpdateFlags(a_selectiveUpdate, a_selectiveUpdateTransforms, a_rigid);
    if (FieldAt<void*>(this, 0x130) != nullptr) {
        FieldAt<std::uint32_t>(this, 0xf4) |= 0x4;
        a_selectiveUpdate = true;
        FieldAt<std::uint32_t>(this, 0xf4) |= 0x2;
        a_rigid = false;
    }
}

// Body done: RVA 0xefc380, 121 bytes, BSGeometry::RegisterStreamables.
bool BSGeometry::RegisterStreamables(NiStream& a_stream)
{
    if (!BaseRegisterStreamables(a_stream)) {
        return false;
    }
    if (NiObject* child130 = FieldAt<NiObject*>(this, 0x130)) {
        child130->RegisterStreamables(a_stream);
    }
    if (NiObject* child128 = FieldAt<NiObject*>(this, 0x128)) {
        child128->RegisterStreamables(a_stream);
    }
    if (NiObject* child120 = FieldAt<NiObject*>(this, 0x120)) {
        child120->RegisterStreamables(a_stream);
    }
    return true;
}
