// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing and community declarations only
// DragonCameraState, DragonCameraState::Begin, DragonCameraState::~DragonCameraState, DragonCameraState::End, DragonCameraState::SaveGame, DragonCameraState::LoadGame, DragonCameraState::Revert, DragonCameraState::SetCameraHandle, DragonCameraState::Unk_0A, DragonCameraState::ProcessWeaponDrawnChange, DragonCameraState::GetFreeRotationMode, DragonCameraState::SetFreeRotationMode, DragonCameraState::UpdateRotation, DragonCameraState::HandleLookInput: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BGSSaveFormBuffer, NiPoint2: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); forward declarations only
// ThirdPersonState, ThirdPersonState::~ThirdPersonState, ThirdPersonState::Begin, ThirdPersonState::CanProcess, ThirdPersonState::End, ThirdPersonState::Update, ThirdPersonState::GetRotation, ThirdPersonState::ProcessButton, ThirdPersonState::GetTranslation, ThirdPersonState::SaveGame, ThirdPersonState::LoadGame, ThirdPersonState::Revert, ThirdPersonState::SetCameraHandle, ThirdPersonState::Unk_0A, ThirdPersonState::ProcessWeaponDrawnChange, ThirdPersonState::GetFreeRotationMode, ThirdPersonState::SetFreeRotationMode, ThirdPersonState::UpdateRotation, ThirdPersonState::HandleLookInput, ThirdPersonState::thirdPersonCameraObj, ThirdPersonState::thirdPersonFOVControl, ThirdPersonState::translation, ThirdPersonState::rotation, ThirdPersonState::posOffsetExpected, ThirdPersonState::posOffsetActual, ThirdPersonState::targetZoomOffset, ThirdPersonState::currentZoomOffset, ThirdPersonState::targetYaw, ThirdPersonState::currentYaw, ThirdPersonState::savedZoomOffset, ThirdPersonState::pitchZoomOffset, ThirdPersonState::collisionPos, ThirdPersonState::collisionPosValid, ThirdPersonState::animatedBoneName, ThirdPersonState::animationRotation, ThirdPersonState::freeRotation, ThirdPersonState::freeRotationEnabled, ThirdPersonState::stateNotActive, ThirdPersonState::toggleAnimCam, ThirdPersonState::applyOffsets, PlayerInputHandler, PlayerInputHandler::~PlayerInputHandler, PlayerInputHandler::CanProcess, PlayerInputHandler::ProcessThumbstick, PlayerInputHandler::ProcessMouseMove, PlayerInputHandler::ProcessButton, PlayerInputHandler::inputEventHandlingEnabled, RefHandle, InputEvent, ButtonEvent, PlayerControlsData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ThirdPersonState, PlayerInputHandler: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); main's TESCameraState.h and ThirdPersonState.h do not declare these bases with the layout this unit needs
// unknown05, unknown06, unknown09, unknown0A, unknown0C, unknown8C, unknownA0, unknownC0, unknownC8, unknownD0, unknownDE, unknownE4: GUESS(low)
// DragonCameraState::cameraHandle, unknownEC, unknownF0, unknownF1, unknownF2, unknownF4, unknownF8, unknownFC, unknown100, unknown104, unknown108, unknown10C: GUESS(low); the members Begin, End and SetCameraHandle write or no compared code reads
// PlayerCharacter, PlayerCharacter::unkFlagsBED, g_playerCharacterSingleton: GUESS(low); the image reads the pointer at 0x3230778 and the byte at 0xBED, only that byte is declared
// DragonCameraGate, DragonCameraGate::unk4B, g_dragonCameraGate: GUESS(low); the object at 0x31a5698 whose byte at 0x4B gates free rotation, the names are invented
// every member named unknownNN or unkNN in PlayerCharacter and DragonCameraGate: GUESS(low); no compared code reads them
#pragma once

#include <cstdint>
#include <cstddef>
#include "TESCameraState.h"

template <class T>
class BSTSmartPointer;

class NiAVObject;
class NiNode;
class BGSSaveFormBuffer;
using RefHandle = std::uint32_t;
class NiPoint2;
class InputEvent;
class ButtonEvent;
class PlayerControlsData;
class MouseMoveEvent;
class ThumbstickEvent;

class PlayerCharacter
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
    std::uint64_t unknown6A0;  // 6A0
    std::uint64_t unknown6A8;  // 6A8
    std::uint64_t unknown6B0;  // 6B0
    std::uint64_t unknown6B8;  // 6B8
    std::uint64_t unknown6C0;  // 6C0
    std::uint64_t unknown6C8;  // 6C8
    std::uint64_t unknown6D0;  // 6D0
    std::uint64_t unknown6D8;  // 6D8
    std::uint64_t unknown6E0;  // 6E0
    std::uint64_t unknown6E8;  // 6E8
    std::uint64_t unknown6F0;  // 6F0
    std::uint64_t unknown6F8;  // 6F8
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
    std::uint64_t unknown7A0;  // 7A0
    std::uint64_t unknown7A8;  // 7A8
    std::uint64_t unknown7B0;  // 7B0
    std::uint64_t unknown7B8;  // 7B8
    std::uint64_t unknown7C0;  // 7C0
    std::uint64_t unknown7C8;  // 7C8
    std::uint64_t unknown7D0;  // 7D0
    std::uint64_t unknown7D8;  // 7D8
    std::uint64_t unknown7E0;  // 7E0
    std::uint64_t unknown7E8;  // 7E8
    std::uint64_t unknown7F0;  // 7F0
    std::uint64_t unknown7F8;  // 7F8
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
    std::uint64_t unknown8A0;  // 8A0
    std::uint64_t unknown8A8;  // 8A8
    std::uint64_t unknown8B0;  // 8B0
    std::uint64_t unknown8B8;  // 8B8
    std::uint64_t unknown8C0;  // 8C0
    std::uint64_t unknown8C8;  // 8C8
    std::uint64_t unknown8D0;  // 8D0
    std::uint64_t unknown8D8;  // 8D8
    std::uint64_t unknown8E0;  // 8E0
    std::uint64_t unknown8E8;  // 8E8
    std::uint64_t unknown8F0;  // 8F0
    std::uint64_t unknown8F8;  // 8F8
    std::uint64_t unknown900;  // 900
    std::uint64_t unknown908;  // 908
    std::uint64_t unknown910;  // 910
    std::uint64_t unknown918;  // 918
    std::uint64_t unknown920;  // 920
    std::uint64_t unknown928;  // 928
    std::uint64_t unknown930;  // 930
    std::uint64_t unknown938;  // 938
    std::uint64_t unknown940;  // 940
    std::uint64_t unknown948;  // 948
    std::uint64_t unknown950;  // 950
    std::uint64_t unknown958;  // 958
    std::uint64_t unknown960;  // 960
    std::uint64_t unknown968;  // 968
    std::uint64_t unknown970;  // 970
    std::uint64_t unknown978;  // 978
    std::uint64_t unknown980;  // 980
    std::uint64_t unknown988;  // 988
    std::uint64_t unknown990;  // 990
    std::uint64_t unknown998;  // 998
    std::uint64_t unknown9A0;  // 9A0
    std::uint64_t unknown9A8;  // 9A8
    std::uint64_t unknown9B0;  // 9B0
    std::uint64_t unknown9B8;  // 9B8
    std::uint64_t unknown9C0;  // 9C0
    std::uint64_t unknown9C8;  // 9C8
    std::uint64_t unknown9D0;  // 9D0
    std::uint64_t unknown9D8;  // 9D8
    std::uint64_t unknown9E0;  // 9E0
    std::uint64_t unknown9E8;  // 9E8
    std::uint64_t unknown9F0;  // 9F0
    std::uint64_t unknown9F8;  // 9F8
    std::uint64_t unknownA00;  // A00
    std::uint64_t unknownA08;  // A08
    std::uint64_t unknownA10;  // A10
    std::uint64_t unknownA18;  // A18
    std::uint64_t unknownA20;  // A20
    std::uint64_t unknownA28;  // A28
    std::uint64_t unknownA30;  // A30
    std::uint64_t unknownA38;  // A38
    std::uint64_t unknownA40;  // A40
    std::uint64_t unknownA48;  // A48
    std::uint64_t unknownA50;  // A50
    std::uint64_t unknownA58;  // A58
    std::uint64_t unknownA60;  // A60
    std::uint64_t unknownA68;  // A68
    std::uint64_t unknownA70;  // A70
    std::uint64_t unknownA78;  // A78
    std::uint64_t unknownA80;  // A80
    std::uint64_t unknownA88;  // A88
    std::uint64_t unknownA90;  // A90
    std::uint64_t unknownA98;  // A98
    std::uint64_t unknownAA0;  // AA0
    std::uint64_t unknownAA8;  // AA8
    std::uint64_t unknownAB0;  // AB0
    std::uint64_t unknownAB8;  // AB8
    std::uint64_t unknownAC0;  // AC0
    std::uint64_t unknownAC8;  // AC8
    std::uint64_t unknownAD0;  // AD0
    std::uint64_t unknownAD8;  // AD8
    std::uint64_t unknownAE0;  // AE0
    std::uint64_t unknownAE8;  // AE8
    std::uint64_t unknownAF0;  // AF0
    std::uint64_t unknownAF8;  // AF8
    std::uint64_t unknownB00;  // B00
    std::uint64_t unknownB08;  // B08
    std::uint64_t unknownB10;  // B10
    std::uint64_t unknownB18;  // B18
    std::uint64_t unknownB20;  // B20
    std::uint64_t unknownB28;  // B28
    std::uint64_t unknownB30;  // B30
    std::uint64_t unknownB38;  // B38
    std::uint64_t unknownB40;  // B40
    std::uint64_t unknownB48;  // B48
    std::uint64_t unknownB50;  // B50
    std::uint64_t unknownB58;  // B58
    std::uint64_t unknownB60;  // B60
    std::uint64_t unknownB68;  // B68
    std::uint64_t unknownB70;  // B70
    std::uint64_t unknownB78;  // B78
    std::uint64_t unknownB80;  // B80
    std::uint64_t unknownB88;  // B88
    std::uint64_t unknownB90;  // B90
    std::uint64_t unknownB98;  // B98
    std::uint64_t unknownBA0;  // BA0
    std::uint64_t unknownBA8;  // BA8
    std::uint64_t unknownBB0;  // BB0
    std::uint64_t unknownBB8;  // BB8
    std::uint64_t unknownBC0;  // BC0
    std::uint64_t unknownBC8;  // BC8
    std::uint64_t unknownBD0;  // BD0
    std::uint64_t unknownBD8;  // BD8
    std::uint64_t unknownBE0;  // BE0
    std::uint32_t unknownBE8;  // BE8
    std::uint8_t unknownBEC;  // BEC
    std::uint8_t unkFlagsBED;  // BED
};

class DragonCameraGate
{
public:
    std::uint64_t unknown00;  // 00
    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint16_t unknown48;  // 48
    std::uint8_t unknown4A;  // 4A
    std::uint8_t unk4B;  // 4B
};

extern PlayerCharacter* g_playerCharacterSingleton;
extern DragonCameraGate* g_dragonCameraGate;

class PlayerInputHandler
{
public:
    virtual ~PlayerInputHandler();  // 00
    virtual bool CanProcess(InputEvent* a_event) = 0;  // 01
    virtual void ProcessThumbstick(ThumbstickEvent* a_event, PlayerControlsData* a_data);  // 02
    virtual void ProcessMouseMove(MouseMoveEvent* a_event, PlayerControlsData* a_data);  // 03
    virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data);  // 04

    bool inputEventHandlingEnabled;  // 08
    std::uint8_t unknown09;  // 09
    std::uint16_t unknown0A;  // 0A
    std::uint32_t unknown0C;  // 0C
};
static_assert(sizeof(PlayerInputHandler) == 0x10, "PlayerInputHandler size");

class ThirdPersonState : public TESCameraState, public PlayerInputHandler
{
public:
    virtual ~ThirdPersonState();  // 00
    void Begin() override;  // 01
    bool CanProcess(InputEvent* a_event) override;  // 01
    void End() override;  // 02
    virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState);  // 03
    void GetRotation(NiQuaternion& a_rotation) override;  // 04
    void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_movementData) override;  // 04
    void GetTranslation(NiPoint3& a_translation) override;  // 05
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);  // 06
    void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 07
    virtual void Revert(BGSLoadFormBuffer* a_buf);  // 08
    virtual void SetCameraHandle(RefHandle& a_handle);  // 09
    virtual void Unk_0A(void);  // 0A
    virtual void ProcessWeaponDrawnChange(bool a_drawn);  // 0B
    virtual bool GetFreeRotationMode() const;  // 0C
    virtual void SetFreeRotationMode(bool a_weaponSheathed);  // 0D
    virtual void UpdateRotation();  // 0E
    virtual void HandleLookInput(const NiPoint2& a_input);  // 0F

    NiAVObject* thirdPersonCameraObj;  // 30
    NiNode* thirdPersonFOVControl;  // 38
    NiPoint3 translation;  // 40
    NiQuaternion rotation;  // 4C
    NiPoint3 posOffsetExpected;  // 5C
    NiPoint3 posOffsetActual;  // 68
    float targetZoomOffset;  // 74
    float currentZoomOffset;  // 78
    float targetYaw;  // 7C
    float currentYaw;  // 80
    float savedZoomOffset;  // 84
    float pitchZoomOffset;  // 88
    float unknown8C;  // 8C
    NiPoint3 collisionPos;  // 90
    float collisionPosValid;  // 9C
    std::uint64_t unknownA0;  // A0
    void* animatedBoneName;  // A8
    NiQuaternion animationRotation;  // B0
    std::uint64_t unknownC0;  // C0
    std::uint64_t unknownC8;  // C8
    std::uint32_t unknownD0;  // D0
    float freeRotation[2];  // D4
    bool freeRotationEnabled;  // DC
    bool stateNotActive;  // DD
    std::uint16_t unknownDE;  // DE
    bool toggleAnimCam;  // E0
    bool applyOffsets;  // E1
    std::uint16_t unknownE2;  // E2
    std::uint32_t unknownE4;  // E4
};
static_assert(sizeof(ThirdPersonState) == 0xE8, "ThirdPersonState size");

class DragonCameraState : public ThirdPersonState
{
public:
    // Declared so that the unit emits the class vftables and the scalar deleting destructor.
    DragonCameraState();  // 00
    // The target inlines the complete destructor, so the body is empty.
    ~DragonCameraState() {}  // 00
    void Begin() override;  // compared: 0x55c740  // slot 01
    void End() override;  // 02
    void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 06
    void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 07
    void Revert(BGSLoadFormBuffer* a_buf) override;  // 08
    void SetCameraHandle(RefHandle& a_handle) override;  // 09
    void Unk_0A(void) override;  // 0A
    void ProcessWeaponDrawnChange(bool a_drawn) override;  // 0B
    bool GetFreeRotationMode() const override;  // 0C
    void SetFreeRotationMode(bool a_weaponSheathed) override;  // 0D
    void UpdateRotation() override;  // 0E
    void HandleLookInput(const NiPoint2& a_input) override;  // 0F

    RefHandle cameraHandle;  // E8
    float unknownEC;  // EC
    std::uint8_t unknownF0;  // F0
    std::uint8_t unknownF1;  // F1
    std::uint16_t unknownF2;  // F2
    float unknownF4;  // F4
    std::uint8_t unknownF8;  // F8
    float unknownFC;  // FC
    float unknown100;  // 100
    float unknown104;  // 104
    float unknown108;  // 108
    RefHandle unknown10C;  // 10C
};
static_assert(sizeof(DragonCameraState) == 0x110, "DragonCameraState size");
