// Source exposure: mixed (local binary analysis and public names).
// Code origin: original reconstruction from the pinned listing and community declarations (names only); no adapted body.
// Adapted bodies: none.
// PlayerCharacter, Slot8: GUESS(low); vtable owner and slot; method spelling invented.
// PlayerCharacter::Slot8: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x75d390 PlayerCharacter::Function75d390
// MagicTargetPrefix: STANDIN GUESS(low); invented prefix name for the MagicTarget-shaped receiver subobject at 0xa0, sized only.
// flags, postUpdateDispelList: GUESS(low); spellings follow NG's MagicTarget fields, the prefix above is invented.
// unknown08 to unknown8f0, unknown14, unknown98, unknown8f0: GUESS(low); unaccessed fields at their measured offsets.
// magicTarget: GUESS(low); the target adds 0xa0 to the receiver and passes that address to the callee.
// sleepSeconds: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG names the runtime word, the offset here is measured.
// PlayerCharacterManager, unknown160: GUESS(low); pointer global whose word at 0x160 is compared with zero.
// Function5d2080: GUESS(low); callee at RVA 0x5d2080, first argument and one float evidenced by the tail jump.
// g_playerCharacterManager: GUESS(low); the global at RVA 0x219e5c0.
#pragma once
#include <cstddef>
#include <cstdint>

struct MagicTargetPrefix
{
    const void*    vtable;               // 00
    void*          postUpdateDispelList;  // 08
    std::uint32_t  flags;                // 10
    std::uint32_t  unknown14;            // 14
};
static_assert(sizeof(MagicTargetPrefix) == 0x18, "MagicTargetPrefix size");

struct PlayerCharacterManager
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
    std::uint64_t unknown0a0;  // 0a0
    std::uint64_t unknown0a8;  // 0a8
    std::uint64_t unknown0b0;  // 0b0
    std::uint64_t unknown0b8;  // 0b8
    std::uint64_t unknown0c0;  // 0c0
    std::uint64_t unknown0c8;  // 0c8
    std::uint64_t unknown0d0;  // 0d0
    std::uint64_t unknown0d8;  // 0d8
    std::uint64_t unknown0e0;  // 0e0
    std::uint64_t unknown0e8;  // 0e8
    std::uint64_t unknown0f0;  // 0f0
    std::uint64_t unknown0f8;  // 0f8
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
    std::uint32_t unknown160;    // 160
};
static_assert(offsetof(PlayerCharacterManager, unknown160) == 0x160, "manager word offset");

extern PlayerCharacterManager* g_playerCharacterManager;

class PlayerCharacter
{
public:
    virtual std::uint8_t Slot8() const;
    void Function75d390();

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70
    std::uint64_t unknown78;  // 78
    std::uint64_t unknown80;  // 80
    std::uint64_t unknown88;  // 88
    std::uint64_t unknown90;  // 90
    std::uint64_t unknown98;    // 98
    MagicTargetPrefix magicTarget;  // a0
    std::uint64_t unknown0b8;  // 0b8
    std::uint64_t unknown0c0;  // 0c0
    std::uint64_t unknown0c8;  // 0c8
    std::uint64_t unknown0d0;  // 0d0
    std::uint64_t unknown0d8;  // 0d8
    std::uint64_t unknown0e0;  // 0e0
    std::uint64_t unknown0e8;  // 0e8
    std::uint64_t unknown0f0;  // 0f0
    std::uint64_t unknown0f8;  // 0f8
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
    std::uint64_t unknown1a0;  // 1a0
    std::uint64_t unknown1a8;  // 1a8
    std::uint64_t unknown1b0;  // 1b0
    std::uint64_t unknown1b8;  // 1b8
    std::uint64_t unknown1c0;  // 1c0
    std::uint64_t unknown1c8;  // 1c8
    std::uint64_t unknown1d0;  // 1d0
    std::uint64_t unknown1d8;  // 1d8
    std::uint64_t unknown1e0;  // 1e0
    std::uint64_t unknown1e8;  // 1e8
    std::uint64_t unknown1f0;  // 1f0
    std::uint64_t unknown1f8;  // 1f8
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
    std::uint64_t unknown2a0;  // 2a0
    std::uint64_t unknown2a8;  // 2a8
    std::uint64_t unknown2b0;  // 2b0
    std::uint64_t unknown2b8;  // 2b8
    std::uint64_t unknown2c0;  // 2c0
    std::uint64_t unknown2c8;  // 2c8
    std::uint64_t unknown2d0;  // 2d0
    std::uint64_t unknown2d8;  // 2d8
    std::uint64_t unknown2e0;  // 2e0
    std::uint64_t unknown2e8;  // 2e8
    std::uint64_t unknown2f0;  // 2f0
    std::uint64_t unknown2f8;  // 2f8
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
    std::uint64_t unknown3a0;  // 3a0
    std::uint64_t unknown3a8;  // 3a8
    std::uint64_t unknown3b0;  // 3b0
    std::uint64_t unknown3b8;  // 3b8
    std::uint64_t unknown3c0;  // 3c0
    std::uint64_t unknown3c8;  // 3c8
    std::uint64_t unknown3d0;  // 3d0
    std::uint64_t unknown3d8;  // 3d8
    std::uint64_t unknown3e0;  // 3e0
    std::uint64_t unknown3e8;  // 3e8
    std::uint64_t unknown3f0;  // 3f0
    std::uint64_t unknown3f8;  // 3f8
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
    std::uint64_t unknown4a0;  // 4a0
    std::uint64_t unknown4a8;  // 4a8
    std::uint64_t unknown4b0;  // 4b0
    std::uint64_t unknown4b8;  // 4b8
    std::uint64_t unknown4c0;  // 4c0
    std::uint64_t unknown4c8;  // 4c8
    std::uint64_t unknown4d0;  // 4d0
    std::uint64_t unknown4d8;  // 4d8
    std::uint64_t unknown4e0;  // 4e0
    std::uint64_t unknown4e8;  // 4e8
    std::uint64_t unknown4f0;  // 4f0
    std::uint64_t unknown4f8;  // 4f8
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
    std::uint64_t unknown5a0;  // 5a0
    std::uint64_t unknown5a8;  // 5a8
    std::uint64_t unknown5b0;  // 5b0
    std::uint64_t unknown5b8;  // 5b8
    std::uint64_t unknown5c0;  // 5c0
    std::uint64_t unknown5c8;  // 5c8
    std::uint64_t unknown5d0;  // 5d0
    std::uint64_t unknown5d8;  // 5d8
    std::uint64_t unknown5e0;  // 5e0
    std::uint64_t unknown5e8;  // 5e8
    std::uint64_t unknown5f0;  // 5f0
    std::uint64_t unknown5f8;  // 5f8
    std::uint64_t unknown600;  // 600
    std::uint64_t unknown608;  // 608
    std::uint64_t unknown610;  // 610
    std::uint64_t unknown618;  // 618
    std::uint64_t unknown620;  // 620
    std::uint64_t unknown628;  // 628
    std::uint64_t unknown630;  // 630
    std::uint64_t unknown638;  // 638
    std::uint64_t unknown640;  // 640
    std::uint64_t unknown648;  // 648
    std::uint64_t unknown650;  // 650
    std::uint64_t unknown658;  // 658
    std::uint64_t unknown660;  // 660
    std::uint64_t unknown668;  // 668
    std::uint64_t unknown670;  // 670
    std::uint64_t unknown678;  // 678
    std::uint64_t unknown680;  // 680
    std::uint64_t unknown688;  // 688
    std::uint64_t unknown690;  // 690
    std::uint64_t unknown698;  // 698
    std::uint64_t unknown6a0;  // 6a0
    std::uint64_t unknown6a8;  // 6a8
    std::uint64_t unknown6b0;  // 6b0
    std::uint64_t unknown6b8;  // 6b8
    std::uint64_t unknown6c0;  // 6c0
    std::uint64_t unknown6c8;  // 6c8
    std::uint64_t unknown6d0;  // 6d0
    std::uint64_t unknown6d8;  // 6d8
    std::uint64_t unknown6e0;  // 6e0
    std::uint64_t unknown6e8;  // 6e8
    std::uint64_t unknown6f0;  // 6f0
    std::uint64_t unknown6f8;  // 6f8
    std::uint64_t unknown700;  // 700
    std::uint64_t unknown708;  // 708
    std::uint64_t unknown710;  // 710
    std::uint64_t unknown718;  // 718
    std::uint64_t unknown720;  // 720
    std::uint64_t unknown728;  // 728
    std::uint64_t unknown730;  // 730
    std::uint64_t unknown738;  // 738
    std::uint64_t unknown740;  // 740
    std::uint64_t unknown748;  // 748
    std::uint64_t unknown750;  // 750
    std::uint64_t unknown758;  // 758
    std::uint64_t unknown760;  // 760
    std::uint64_t unknown768;  // 768
    std::uint64_t unknown770;  // 770
    std::uint64_t unknown778;  // 778
    std::uint64_t unknown780;  // 780
    std::uint64_t unknown788;  // 788
    std::uint64_t unknown790;  // 790
    std::uint64_t unknown798;  // 798
    std::uint64_t unknown7a0;  // 7a0
    std::uint64_t unknown7a8;  // 7a8
    std::uint64_t unknown7b0;  // 7b0
    std::uint64_t unknown7b8;  // 7b8
    std::uint64_t unknown7c0;  // 7c0
    std::uint64_t unknown7c8;  // 7c8
    std::uint64_t unknown7d0;  // 7d0
    std::uint64_t unknown7d8;  // 7d8
    std::uint64_t unknown7e0;  // 7e0
    std::uint64_t unknown7e8;  // 7e8
    std::uint64_t unknown7f0;  // 7f0
    std::uint64_t unknown7f8;  // 7f8
    std::uint64_t unknown800;  // 800
    std::uint64_t unknown808;  // 808
    std::uint64_t unknown810;  // 810
    std::uint64_t unknown818;  // 818
    std::uint64_t unknown820;  // 820
    std::uint64_t unknown828;  // 828
    std::uint64_t unknown830;  // 830
    std::uint64_t unknown838;  // 838
    std::uint64_t unknown840;  // 840
    std::uint64_t unknown848;  // 848
    std::uint64_t unknown850;  // 850
    std::uint64_t unknown858;  // 858
    std::uint64_t unknown860;  // 860
    std::uint64_t unknown868;  // 868
    std::uint64_t unknown870;  // 870
    std::uint64_t unknown878;  // 878
    std::uint64_t unknown880;  // 880
    std::uint64_t unknown888;  // 888
    std::uint64_t unknown890;  // 890
    std::uint64_t unknown898;  // 898
    std::uint64_t unknown8a0;  // 8a0
    std::uint64_t unknown8a8;  // 8a8
    std::uint64_t unknown8b0;  // 8b0
    std::uint64_t unknown8b8;  // 8b8
    std::uint64_t unknown8c0;  // 8c0
    std::uint64_t unknown8c8;  // 8c8
    std::uint64_t unknown8d0;  // 8d0
    std::uint64_t unknown8d8;  // 8d8
    std::uint64_t unknown8e0;  // 8e0
    std::uint64_t unknown8e8;  // 8e8
    std::uint32_t unknown8f0;  // 8f0
    std::uint32_t sleepSeconds;  // 8f4
};
static_assert(offsetof(PlayerCharacter, magicTarget) == 0xa0, "receiver subobject offset");
static_assert(offsetof(PlayerCharacter, sleepSeconds) == 0x8f4, "runtime word offset");
static_assert(sizeof(PlayerCharacter) == 0x8f8, "PlayerCharacter size");

// Function5d2080: GUESS(low); declared only, the target tail-jumps to RVA 0x5d2080.
void Function5d2080(MagicTargetPrefix* a_target, float a_value);
