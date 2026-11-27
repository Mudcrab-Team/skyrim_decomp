// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter, Func279_1406B45C0, NiPoint3, x, y, z: CRASHLOGGER_PDB(59818@2026.10.24)
// PlayerCamera75bff0, ActorNode75bff0, g_playerCamera75bff0, g_zeroPoint75bff0, unk00, unk08, unk54, unkA0, IsCameraActive, GetNode, VFunc: GUESS(low)
// 0x75bff0 PlayerCharacter::Func279_1406B45C0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct ActorNode75bff0
{
    std::uint8_t unk00[0xA0];
    NiPoint3 unkA0;
};

class PlayerCamera75bff0
{
public:
    virtual void VFunc000();
    virtual void VFunc001();
    virtual void VFunc002();
    virtual void VFunc003();
    virtual void VFunc004();
    virtual void VFunc005();
    virtual void VFunc006();
    virtual void VFunc007();
    virtual void VFunc008();
    virtual void VFunc009();
    virtual void VFunc010();
    virtual void VFunc011();
    virtual void VFunc012();
    virtual void VFunc013();
    virtual void VFunc014();
    virtual void VFunc015();
    virtual void VFunc016();
    virtual void VFunc017();
    virtual void VFunc018();
    virtual void VFunc019();
    virtual void VFunc020();
    virtual void VFunc021();
    virtual void VFunc022();
    virtual void VFunc023();
    virtual void VFunc024();
    virtual void VFunc025();
    virtual void VFunc026();
    virtual void VFunc027();
    virtual void VFunc028();
    virtual void VFunc029();
    virtual void VFunc030();
    virtual void VFunc031();
    virtual void VFunc032();
    virtual void VFunc033();
    virtual void VFunc034();
    virtual void VFunc035();
    virtual void VFunc036();
    virtual void VFunc037();
    virtual void VFunc038();
    virtual void VFunc039();
    virtual void VFunc040();
    virtual void VFunc041();
    virtual void VFunc042();
    virtual void VFunc043();
    virtual void VFunc044();
    virtual void VFunc045();
    virtual void VFunc046();
    virtual void VFunc047();
    virtual void VFunc048();
    virtual void VFunc049();
    virtual void VFunc050();
    virtual void VFunc051();
    virtual void VFunc052();
    virtual void VFunc053();
    virtual void VFunc054();
    virtual void VFunc055();
    virtual void VFunc056();
    virtual void VFunc057();
    virtual void VFunc058();
    virtual void VFunc059();
    virtual void VFunc060();
    virtual void VFunc061();
    virtual void VFunc062();
    virtual void VFunc063();
    virtual void VFunc064();
    virtual void VFunc065();
    virtual void VFunc066();
    virtual void VFunc067();
    virtual void VFunc068();
    virtual void VFunc069();
    virtual void VFunc070();
    virtual void VFunc071();
    virtual void VFunc072();
    virtual void VFunc073();
    virtual void VFunc074();
    virtual void VFunc075();
    virtual void VFunc076();
    virtual void VFunc077();
    virtual void VFunc078();
    virtual void VFunc079();
    virtual void VFunc080();
    virtual void VFunc081();
    virtual void VFunc082();
    virtual void VFunc083();
    virtual void VFunc084();
    virtual void VFunc085();
    virtual void VFunc086();
    virtual void VFunc087();
    virtual void VFunc088();
    virtual void VFunc089();
    virtual void VFunc090();
    virtual void VFunc091();
    virtual void VFunc092();
    virtual void VFunc093();
    virtual void VFunc094();
    virtual void VFunc095();
    virtual void VFunc096();
    virtual void VFunc097();
    virtual void VFunc098();
    virtual void VFunc099();
    virtual void VFunc100();
    virtual void VFunc101();
    virtual void VFunc102();
    virtual void VFunc103();
    virtual void VFunc104();
    virtual void VFunc105();
    virtual void VFunc106();
    virtual void VFunc107();
    virtual void VFunc108();
    virtual void VFunc109();
    virtual void VFunc110();
    virtual void VFunc111();
    virtual void VFunc112();
    virtual bool IsCameraActive();
};

class PlayerCharacter
{
public:
    virtual void VFunc000();
    virtual void VFunc001();
    virtual void VFunc002();
    virtual void VFunc003();
    virtual void VFunc004();
    virtual void VFunc005();
    virtual void VFunc006();
    virtual void VFunc007();
    virtual void VFunc008();
    virtual void VFunc009();
    virtual void VFunc010();
    virtual void VFunc011();
    virtual void VFunc012();
    virtual void VFunc013();
    virtual void VFunc014();
    virtual void VFunc015();
    virtual void VFunc016();
    virtual void VFunc017();
    virtual void VFunc018();
    virtual void VFunc019();
    virtual void VFunc020();
    virtual void VFunc021();
    virtual void VFunc022();
    virtual void VFunc023();
    virtual void VFunc024();
    virtual void VFunc025();
    virtual void VFunc026();
    virtual void VFunc027();
    virtual void VFunc028();
    virtual void VFunc029();
    virtual void VFunc030();
    virtual void VFunc031();
    virtual void VFunc032();
    virtual void VFunc033();
    virtual void VFunc034();
    virtual void VFunc035();
    virtual void VFunc036();
    virtual void VFunc037();
    virtual void VFunc038();
    virtual void VFunc039();
    virtual void VFunc040();
    virtual void VFunc041();
    virtual void VFunc042();
    virtual void VFunc043();
    virtual void VFunc044();
    virtual void VFunc045();
    virtual void VFunc046();
    virtual void VFunc047();
    virtual void VFunc048();
    virtual void VFunc049();
    virtual void VFunc050();
    virtual void VFunc051();
    virtual void VFunc052();
    virtual void VFunc053();
    virtual void VFunc054();
    virtual void VFunc055();
    virtual void VFunc056();
    virtual void VFunc057();
    virtual void VFunc058();
    virtual void VFunc059();
    virtual void VFunc060();
    virtual void VFunc061();
    virtual void VFunc062();
    virtual void VFunc063();
    virtual void VFunc064();
    virtual void VFunc065();
    virtual void VFunc066();
    virtual void VFunc067();
    virtual void VFunc068();
    virtual void VFunc069();
    virtual void VFunc070();
    virtual void VFunc071();
    virtual void VFunc072();
    virtual void VFunc073();
    virtual void VFunc074();
    virtual void VFunc075();
    virtual void VFunc076();
    virtual void VFunc077();
    virtual void VFunc078();
    virtual void VFunc079();
    virtual void VFunc080();
    virtual void VFunc081();
    virtual void VFunc082();
    virtual void VFunc083();
    virtual void VFunc084();
    virtual void VFunc085();
    virtual void VFunc086();
    virtual void VFunc087();
    virtual void VFunc088();
    virtual void VFunc089();
    virtual void VFunc090();
    virtual void VFunc091();
    virtual void VFunc092();
    virtual void VFunc093();
    virtual void VFunc094();
    virtual void VFunc095();
    virtual void VFunc096();
    virtual void VFunc097();
    virtual void VFunc098();
    virtual void VFunc099();
    virtual void VFunc100();
    virtual void VFunc101();
    virtual void VFunc102();
    virtual void VFunc103();
    virtual void VFunc104();
    virtual void VFunc105();
    virtual void VFunc106();
    virtual void VFunc107();
    virtual void VFunc108();
    virtual void VFunc109();
    virtual void VFunc110();
    virtual ActorNode75bff0* GetNode(bool a_firstPerson);

    void Func279_1406B45C0(NiPoint3* a_out);

    std::uint8_t unk08[0x4C];
    NiPoint3 unk54;
};

extern PlayerCamera75bff0* g_playerCamera75bff0;
extern const NiPoint3 g_zeroPoint75bff0;

static_assert(offsetof(PlayerCharacter, unk54) == 0x54, "unk54 offset");
static_assert(offsetof(ActorNode75bff0, unkA0) == 0xA0, "unkA0 offset");
