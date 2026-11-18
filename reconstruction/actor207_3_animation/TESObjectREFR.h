// TESObjectREFR: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFR, IAnimationGraphManagerHolder, BSFixedString, GetGraphVariableImpl2, GetGraphVariableImpl3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// AnimationNames, GetAnimationNames, sprintName, syncName, IsSprinting, HasSyncSprint, unknownPrefix: STANDIN GUESS(medium); names and variable identity inferred; unaccessed slots unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
namespace P2073 {
struct BSFixedString { const char* data; };
struct AnimationNames { std::uint8_t unknownPrefix[0x350]; BSFixedString sprintName; BSFixedString syncName; };
AnimationNames* GetAnimationNames();
class IAnimationGraphManagerHolder {
public:
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual bool GetGraphVariableImpl2(const BSFixedString&, std::int32_t&) const;
    virtual bool GetGraphVariableImpl3(const BSFixedString&, bool&) const;
};
class TESObjectREFR {
public:
    bool IsSprinting();
    bool HasSyncSprint();
    std::uint8_t unknownPrefix[0x38];
    IAnimationGraphManagerHolder graph;
};
}
