// Source exposure: mixed (names and declarations from community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiStream::Unk_07, NiStream::Save1, NiStream::~NiStream: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream::LoadObjectSizeTable, NiStream::iStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Code origin: original; the listing and community declarations, except the adapted body named below
// Adapted bodies: NiBinaryStream::read, from CharmedBaryon/CommonLibSSE-NG at b93280e (MIT), include/RE/N/NiBinaryStream.h:70 (kept in the stand-in NiBinaryStream, with the read-function call inlined)
// NiBinaryStream, NiBinaryStream::ReadFn, NiBinaryStream::read, NiBinaryStream::_absoluteCurrentPos, NiBinaryStream::_readFn: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk01..unk0F, Unk_10: GUESS(low); placeholder vtable slots that put Unk_10 at slot 16 (offset 0x80), the slot Save1 calls
// streamPtr2A0, unknown0C, unknown008..unknown210, unknown2A8..unknown618: GUESS(low); the pointer at 0x2A0 that Save1 sets and clears; the 0x0C word and the unrecovered ranges otherwise
// NiTLargeArray, NiTLargeArray::_data, NiTLargeArray::_capacity, NiTLargeArray::_freeIdx, NiTLargeArray::_size, NiTLargeArray::_growthSize: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTLargeArray::SetEntryCount: GUESS(low); the out-of-line call that gives the table room for a count of entries
// the complete destructor ??1NiStream: GUESS(low); declared only, bound by address through bind-hints.json
#pragma once

#include <cstdint>
#include <cstddef>

class NiObject;
class BSFixedString;

// NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Another unit (bssystem/NiBinaryStream.h) holds a different partial view of this class; one shared
// declaration is open header work. Only the members the compared body reads are declared here.
class NiBinaryStream
{
public:
    // ReadFn: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    using ReadFn = std::uint32_t(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes,
        std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();  // 00

    // read: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // NiBinaryStream::read and binary_read, inlined: the read advances the stream position by the byte count.
    bool read(std::uint32_t* a_str, std::uint32_t a_count)
    {
        std::uint32_t size = sizeof(std::uint32_t);
        const std::uint32_t toRead = a_count * size;
        const std::uint32_t bytesRead = _readFn(this, a_str, toRead, &size, 1);
        _absoluteCurrentPos += bytesRead;
        return bytesRead == toRead;
    }

    std::uint32_t _absoluteCurrentPos;  // 08
    std::uint32_t unknown0C;            // 0C
    ReadFn* _readFn;                    // 10
};
static_assert(sizeof(NiBinaryStream) == 0x18, "NiBinaryStream size");

// NiTLargeArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// The four element arrays of NiStream share this layout; each differs only in its element type.
template <class T>
class NiTLargeArray
{
public:
    virtual ~NiTLargeArray();  // 00

    // SetEntryCount: GUESS(low); the resize the compared body calls, out of line in the image
    void SetEntryCount(std::uint32_t a_count);

    T* _data;                    // 08
    std::uint32_t _capacity;     // 10
    std::uint32_t _freeIdx;      // 14
    std::uint32_t _size;         // 18
    std::uint32_t _growthSize;   // 1C
};
static_assert(sizeof(NiTLargeArray<std::uint32_t>) == 0x20, "NiTLargeArray size");

class NiStream
{
public:
    NiStream();
    virtual ~NiStream();  // compared: 0xee9550 (scalar deleting destructor; the listing calls the complete destructor)

    // unk01..unk0F: GUESS(low); placeholder slots, only their order matters
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void Unk_07();  // compared: 0xee4710
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void Unk_10();  // slot 16 (offset 0x80), called by Save1

    // Save1: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    void Save1(NiBinaryStream* a_stream);  // compared: 0xee4350

    // LoadObjectSizeTable: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    bool LoadObjectSizeTable();  // compared: 0xee6f60

    // The stream header fields between the vftable and 0x218 are not recovered, and the compared
    // body reads nothing below 0x22C. Each member below is one typed unrecovered slot at its
    // observed offset: the word size follows from the offset column.
    // unknown008..unknown210: GUESS(low); unrecovered stream header words, named by offset only.
    std::uint64_t unknown008;  // 008
    std::uint64_t unknown010;  // 010
    std::uint64_t unknown018;  // 018
    std::uint64_t unknown020;  // 020
    std::uint64_t unknown028;  // 028
    std::uint64_t unknown030;  // 030
    std::uint64_t unknown038;  // 038
    std::uint64_t unknown040;  // 040
    std::uint64_t unknown048;  // 048
    std::uint64_t unknown050;  // 050
    std::uint64_t unknown058;  // 058
    std::uint64_t unknown060;  // 060
    std::uint64_t unknown068;  // 068
    std::uint64_t unknown070;  // 070
    std::uint64_t unknown078;  // 078
    std::uint64_t unknown080;  // 080
    std::uint64_t unknown088;  // 088
    std::uint64_t unknown090;  // 090
    std::uint64_t unknown098;  // 098
    std::uint64_t unknown0A0;  // 0A0
    std::uint64_t unknown0A8;  // 0A8
    std::uint64_t unknown0B0;  // 0B0
    std::uint64_t unknown0B8;  // 0B8
    std::uint64_t unknown0C0;  // 0C0
    std::uint64_t unknown0C8;  // 0C8
    std::uint64_t unknown0D0;  // 0D0
    std::uint64_t unknown0D8;  // 0D8
    std::uint64_t unknown0E0;  // 0E0
    std::uint64_t unknown0E8;  // 0E8
    std::uint64_t unknown0F0;  // 0F0
    std::uint64_t unknown0F8;  // 0F8
    std::uint64_t unknown100;  // 100
    std::uint64_t unknown108;  // 108
    std::uint64_t unknown110;  // 110
    std::uint64_t unknown118;  // 118
    std::uint64_t unknown120;  // 120
    std::uint64_t unknown128;  // 128
    std::uint64_t unknown130;  // 130
    std::uint64_t unknown138;  // 138
    std::uint64_t unknown140;  // 140
    std::uint64_t unknown148;  // 148
    std::uint64_t unknown150;  // 150
    std::uint64_t unknown158;  // 158
    std::uint64_t unknown160;  // 160
    std::uint64_t unknown168;  // 168
    std::uint64_t unknown170;  // 170
    std::uint64_t unknown178;  // 178
    std::uint64_t unknown180;  // 180
    std::uint64_t unknown188;  // 188
    std::uint64_t unknown190;  // 190
    std::uint64_t unknown198;  // 198
    std::uint64_t unknown1A0;  // 1A0
    std::uint64_t unknown1A8;  // 1A8
    std::uint64_t unknown1B0;  // 1B0
    std::uint64_t unknown1B8;  // 1B8
    std::uint64_t unknown1C0;  // 1C0
    std::uint64_t unknown1C8;  // 1C8
    std::uint64_t unknown1D0;  // 1D0
    std::uint64_t unknown1D8;  // 1D8
    std::uint64_t unknown1E0;  // 1E0
    std::uint64_t unknown1E8;  // 1E8
    std::uint64_t unknown1F0;  // 1F0
    std::uint64_t unknown1F8;  // 1F8
    std::uint64_t unknown200;  // 200
    std::uint64_t unknown208;  // 208
    std::uint64_t unknown210;  // 210
    // objects, objectSizes, topObjects, fixedStrings: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    NiTLargeArray<NiObject*> objects;          // 218
    NiTLargeArray<std::uint32_t> objectSizes;  // 238
    NiTLargeArray<NiObject*> topObjects;       // 258
    NiTLargeArray<BSFixedString> fixedStrings;  // 278
    // iStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    NiBinaryStream* iStr;  // 298
    // streamPtr2A0: GUESS(low); set to the argument for the duration of the virtual call in Save1
    NiBinaryStream* streamPtr2A0;  // 2A0
    // unknown2A8..unknown618: GUESS(low); the tail from 0x2A8 to the 0x620 size is not recovered,
    // so each remaining slot is a typed unrecovered word at its observed offset.
    std::uint64_t unknown2A8;  // 2A8
    std::uint64_t unknown2B0;  // 2B0
    std::uint64_t unknown2B8;  // 2B8
    std::uint64_t unknown2C0;  // 2C0
    std::uint64_t unknown2C8;  // 2C8
    std::uint64_t unknown2D0;  // 2D0
    std::uint64_t unknown2D8;  // 2D8
    std::uint64_t unknown2E0;  // 2E0
    std::uint64_t unknown2E8;  // 2E8
    std::uint64_t unknown2F0;  // 2F0
    std::uint64_t unknown2F8;  // 2F8
    std::uint64_t unknown300;  // 300
    std::uint64_t unknown308;  // 308
    std::uint64_t unknown310;  // 310
    std::uint64_t unknown318;  // 318
    std::uint64_t unknown320;  // 320
    std::uint64_t unknown328;  // 328
    std::uint64_t unknown330;  // 330
    std::uint64_t unknown338;  // 338
    std::uint64_t unknown340;  // 340
    std::uint64_t unknown348;  // 348
    std::uint64_t unknown350;  // 350
    std::uint64_t unknown358;  // 358
    std::uint64_t unknown360;  // 360
    std::uint64_t unknown368;  // 368
    std::uint64_t unknown370;  // 370
    std::uint64_t unknown378;  // 378
    std::uint64_t unknown380;  // 380
    std::uint64_t unknown388;  // 388
    std::uint64_t unknown390;  // 390
    std::uint64_t unknown398;  // 398
    std::uint64_t unknown3A0;  // 3A0
    std::uint64_t unknown3A8;  // 3A8
    std::uint64_t unknown3B0;  // 3B0
    std::uint64_t unknown3B8;  // 3B8
    std::uint64_t unknown3C0;  // 3C0
    std::uint64_t unknown3C8;  // 3C8
    std::uint64_t unknown3D0;  // 3D0
    std::uint64_t unknown3D8;  // 3D8
    std::uint64_t unknown3E0;  // 3E0
    std::uint64_t unknown3E8;  // 3E8
    std::uint64_t unknown3F0;  // 3F0
    std::uint64_t unknown3F8;  // 3F8
    std::uint64_t unknown400;  // 400
    std::uint64_t unknown408;  // 408
    std::uint64_t unknown410;  // 410
    std::uint64_t unknown418;  // 418
    std::uint64_t unknown420;  // 420
    std::uint64_t unknown428;  // 428
    std::uint64_t unknown430;  // 430
    std::uint64_t unknown438;  // 438
    std::uint64_t unknown440;  // 440
    std::uint64_t unknown448;  // 448
    std::uint64_t unknown450;  // 450
    std::uint64_t unknown458;  // 458
    std::uint64_t unknown460;  // 460
    std::uint64_t unknown468;  // 468
    std::uint64_t unknown470;  // 470
    std::uint64_t unknown478;  // 478
    std::uint64_t unknown480;  // 480
    std::uint64_t unknown488;  // 488
    std::uint64_t unknown490;  // 490
    std::uint64_t unknown498;  // 498
    std::uint64_t unknown4A0;  // 4A0
    std::uint64_t unknown4A8;  // 4A8
    std::uint64_t unknown4B0;  // 4B0
    std::uint64_t unknown4B8;  // 4B8
    std::uint64_t unknown4C0;  // 4C0
    std::uint64_t unknown4C8;  // 4C8
    std::uint64_t unknown4D0;  // 4D0
    std::uint64_t unknown4D8;  // 4D8
    std::uint64_t unknown4E0;  // 4E0
    std::uint64_t unknown4E8;  // 4E8
    std::uint64_t unknown4F0;  // 4F0
    std::uint64_t unknown4F8;  // 4F8
    std::uint64_t unknown500;  // 500
    std::uint64_t unknown508;  // 508
    std::uint64_t unknown510;  // 510
    std::uint64_t unknown518;  // 518
    std::uint64_t unknown520;  // 520
    std::uint64_t unknown528;  // 528
    std::uint64_t unknown530;  // 530
    std::uint64_t unknown538;  // 538
    std::uint64_t unknown540;  // 540
    std::uint64_t unknown548;  // 548
    std::uint64_t unknown550;  // 550
    std::uint64_t unknown558;  // 558
    std::uint64_t unknown560;  // 560
    std::uint64_t unknown568;  // 568
    std::uint64_t unknown570;  // 570
    std::uint64_t unknown578;  // 578
    std::uint64_t unknown580;  // 580
    std::uint64_t unknown588;  // 588
    std::uint64_t unknown590;  // 590
    std::uint64_t unknown598;  // 598
    std::uint64_t unknown5A0;  // 5A0
    std::uint64_t unknown5A8;  // 5A8
    std::uint64_t unknown5B0;  // 5B0
    std::uint64_t unknown5B8;  // 5B8
    std::uint64_t unknown5C0;  // 5C0
    std::uint64_t unknown5C8;  // 5C8
    std::uint64_t unknown5D0;  // 5D0
    std::uint64_t unknown5D8;  // 5D8
    std::uint64_t unknown5E0;  // 5E0
    std::uint64_t unknown5E8;  // 5E8
    std::uint64_t unknown5F0;  // 5F0
    std::uint64_t unknown5F8;  // 5F8
    std::uint64_t unknown600;  // 600
    std::uint64_t unknown608;  // 608
    std::uint64_t unknown610;  // 610
    std::uint64_t unknown618;  // 618
};
static_assert(sizeof(NiStream) == 0x620, "NiStream size");
