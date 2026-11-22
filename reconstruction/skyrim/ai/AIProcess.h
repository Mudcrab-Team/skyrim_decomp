// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing, community declarations and the CrashLogger PDB names and layout only
// AIProcess, AIProcess::middleHigh, AIProcess::high, AIProcess::ClearMuzzleFlashes, AIProcess::SetHeadtrackTarget, MiddleHighProcessData, MiddleHighProcessData::runOncePackage, MiddleHighProcessData::leftHand, MiddleHighProcessData::rightHand, MiddleHighProcessData::unk326, InventoryEntryData, InventoryEntryData::object, ActorPackage, ActorPackage::package, HighProcessData, HighProcessData::muzzleFlash, HighProcessData::MuzzleFlash, TESForm, TESForm::formType, FormType, FormType::Weapon, NiPoint3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); SetHeadtrackTarget takes an ActorPrefix* here where NG has an Actor*, a guess
// AIProcess::GetCurrentWeapon, AIProcess::SetRunOncePackage: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// TESForm, InventoryEntryData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); main's TESForm.h and InventoryChanges.h do not declare the fields read here (formType, object as a TESForm), so partial views are repeated
// HighProcessData::MuzzleFlash::~MuzzleFlash: GUESS(low); NG's destructor is implicit and non-trivial, declared here and not defined
// GetHeadtrackData, ReleaseRunOncePackage, ClearRunOncePackageData, UpdateRunOncePackage, ActorPackage::SetPackage, ActorPackage::ClearPackage, ActorTargetSlot::SetTarget, CreateActorPackageData: GUESS(low)
// HeadtrackTargetData, ActorTargetSlot, ActorPrefix: STANDIN GUESS(low); partial views with no full layout or ownership claim
// every member named unknownNN: GUESS(low); the compared bodies read none of them
// AIProcess::GetLastSeenLocation, MiddleHighProcessData::lastSeenPosition, HighProcessData::deathForceDirection, HighProcessData::deathForce, HighProcessData::actorsGeneratedDetectionEvent, HighProcessData::unk298, HighProcessData::unk465, HighProcessData::unk46A: CRASHLOGGER_PDB(59818@2026.10.24)
// HighProcessData::unk278, HighProcessData::unk28C, HighProcessData::unk463, HighProcessData::unk464, HighProcessData::unk466, HighProcessData::unk467, HighProcessData::unk469: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HighProcessData::unk460, HighProcessData::unk461, HighProcessData::unk462, HighProcessData::unk468, HighProcessData::unk46B: GUESS(low); the bytes around the two read bools are split out as single members
// defaultDeathForce, defaultDeathForceDirection, DetectionEvent: GUESS(low); the globals are the fallbacks the compared bodies read, named for their use
#pragma once

#include <cstdint>
#include <cstddef>

enum class FormType : std::uint8_t
{
    Weapon = 0x29
};

class TESForm
{
public:
    std::uint64_t unknown00;  // 00
    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint16_t unknown18;  // 18
    std::uint8_t formType;  // 1A
    std::uint8_t unknown1B;  // 1B
    std::uint32_t unknown1C;  // 1C
};
static_assert(sizeof(TESForm) == 0x20, "TESForm size");

class InventoryEntryData
{
public:
    TESForm* object;  // 00
    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
};
static_assert(sizeof(InventoryEntryData) == 0x18, "InventoryEntryData size");

class TESPackage;
class Actor;
struct ActorPackageData;

struct ActorPackage
{
    void SetPackage(TESPackage* a_package, ActorPackageData* a_data, Actor* a_actor);
    void ClearPackage(Actor* a_actor);

    std::uint64_t unknown00;  // 00
    TESPackage* package;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
};
static_assert(sizeof(ActorPackage) == 0x30, "ActorPackage size");

class NiPoint3
{
public:
    float x;  // 0
    float y;  // 4
    float z;  // 8
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

struct DetectionEvent;

struct MiddleHighProcessData
{
public:
    std::uint64_t unknown000;  // 000
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
    ActorPackage runOncePackage;  // 058
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
    NiPoint3 lastSeenPosition;  // 0E0
    std::uint32_t unknown0EC;  // 0EC
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
    std::uint64_t unknown218;  // 218
    InventoryEntryData* leftHand;  // 220
    std::uint64_t unknown228;  // 228
    std::uint64_t unknown230;  // 230
    std::uint64_t unknown238;  // 238
    std::uint64_t unknown240;  // 240
    std::uint64_t unknown248;  // 248
    std::uint64_t unknown250;  // 250
    std::uint64_t unknown258;  // 258
    InventoryEntryData* rightHand;  // 260
    std::uint64_t unknown268;  // 268
    std::uint64_t unknown270;  // 270
    std::uint64_t unknown278;  // 278
    std::uint64_t unknown280;  // 280
    std::uint64_t unknown288;  // 288
    std::uint64_t unknown290;  // 290
    std::uint64_t unknown298;  // 298
    std::uint64_t unknown2A0;  // 2A0
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
    std::uint32_t unknown320;  // 320
    std::uint16_t unknown324;  // 324
    bool unk326;  // 326
    std::uint8_t unknown327;  // 327
    std::uint64_t unknown328;  // 328
    std::uint64_t unknown330;  // 330
};
static_assert(sizeof(MiddleHighProcessData) == 0x338, "MiddleHighProcessData size");

struct HighProcessData
{
    struct MuzzleFlash
    {
        ~MuzzleFlash();

        std::uint64_t unknown000;  // 000
        std::uint64_t unknown008;  // 008
        std::uint64_t unknown010;  // 010
        std::uint64_t unknown018;  // 018
        std::uint64_t unknown020;  // 020
        std::uint64_t unknown028;  // 028
        std::uint64_t unknown030;  // 030
        std::uint64_t unknown038;  // 038
    };
    static_assert(sizeof(MuzzleFlash) == 0x40, "MuzzleFlash size");

    std::uint64_t unknown000;  // 000
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
    std::uint64_t unknown218;  // 218
    std::uint64_t unknown220;  // 220
    std::uint64_t unknown228;  // 228
    std::uint64_t unknown230;  // 230
    std::uint64_t unknown238;  // 238
    std::uint64_t unknown240;  // 240
    std::uint64_t unknown248;  // 248
    std::uint64_t unknown250;  // 250
    std::uint64_t unknown258;  // 258
    std::uint64_t unknown260;  // 260
    std::uint64_t unknown268;  // 268
    std::uint64_t unknown270;  // 270
    float unk278;  // 278
    NiPoint3 deathForceDirection;  // 27C
    float deathForce;  // 288
    float unk28C;  // 28C
    std::uint64_t unknown290;  // 290
    float unk298;  // 298
    std::uint32_t unknown29C;  // 29C
    std::uint64_t unknown2A0;  // 2A0
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
    MuzzleFlash* muzzleFlash;  // 3C8
    std::uint64_t unknown3D0;  // 3D0
    DetectionEvent* actorsGeneratedDetectionEvent;  // 3D8
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
    bool unk460;  // 460
    bool unk461;  // 461
    bool unk462;  // 462
    bool unk463;  // 463
    bool unk464;  // 464
    bool unk465;  // 465
    bool unk466;  // 466
    bool unk467;  // 467
    bool unk468;  // 468
    bool unk469;  // 469
    bool unk46A;  // 46A
    bool unk46B;  // 46B
    std::uint32_t unknown46C;  // 46C
    std::uint64_t unknown470;  // 470
};
static_assert(sizeof(HighProcessData) == 0x478, "HighProcessData size");

struct HeadtrackTargetData
{
    std::uint64_t unknown000;  // 000
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
    std::uint64_t unknown218;  // 218
    std::uint64_t unknown220;  // 220
    std::uint64_t unknown228;  // 228
    std::uint64_t unknown230;  // 230
    std::uint64_t unknown238;  // 238
    std::uint64_t unknown240;  // 240
    std::uint64_t unknown248;  // 248
    std::uint64_t unknown250;  // 250
    std::uint64_t unknown258;  // 258
    std::uint64_t unknown260;  // 260
    std::uint64_t unknown268;  // 268
    std::uint64_t unknown270;  // 270
    std::uint64_t unknown278;  // 278
    std::uint64_t unknown280;  // 280
    std::uint64_t unknown288;  // 288
    std::uint64_t unknown290;  // 290
    std::uint64_t unknown298;  // 298
    std::uint64_t unknown2A0;  // 2A0
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
    std::uint32_t unknown490;  // 490
};

struct ActorTargetSlot
{
    void SetTarget(std::uint32_t* a_data, NiPoint3& a_position);

    std::uint64_t unknown00;  // 00
};

struct ActorPrefix
{
    std::uint64_t unknown000;  // 000
    std::uint64_t unknown008;  // 008
    std::uint64_t unknown010;  // 010
    std::uint64_t unknown018;  // 018
    std::uint64_t unknown020;  // 020
    std::uint64_t unknown028;  // 028
    std::uint64_t unknown030;  // 030
    ActorTargetSlot unknown038;  // 038
};

extern float defaultDeathForce;
extern NiPoint3 defaultDeathForceDirection;

class AIProcess
{
public:
    void ClearMuzzleFlashes();
    InventoryEntryData* GetCurrentWeapon(bool a_leftHand) const;
    NiPoint3* GetLastSeenLocation();
    HeadtrackTargetData* GetHeadtrackData();
    void SetHeadtrackTarget(ActorPrefix* a_owner, NiPoint3& a_targetPosition);
    void SetRunOncePackage(TESPackage* a_package, Actor* a_actor);
    void Function6f1bd0(bool a_value);
    void Function6f2520();
    DetectionEvent* Function6f2540();
    bool Function6ff190();
    float Function6ff1e0();
    void Function6ff210(float a_value);
    void Function6ff230();
    NiPoint3* Function6ff250();
    HighProcessData::MuzzleFlash* Function6ff360();

    std::uint64_t unknown000;  // 000
    MiddleHighProcessData* middleHigh;  // 008
    HighProcessData* high;  // 010
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

private:
    void ReleaseRunOncePackage();
    void ClearRunOncePackageData();
    void UpdateRunOncePackage();
};
static_assert(sizeof(AIProcess) == 0x140, "AIProcess size");
