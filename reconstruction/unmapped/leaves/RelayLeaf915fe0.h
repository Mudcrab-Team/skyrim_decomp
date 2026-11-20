// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x2dd530 (reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp); no external declaration or body reused.
// RelayLeaf915fe0: GUESS(low) STANDIN
// Related, Relay, GetRelated, Step: GUESS(low) STANDIN
#pragma once

class RelayLeaf915fe0;

class Related
{
public:
    void* Step(RelayLeaf915fe0* owner);
};

class RelayLeaf915fe0
{
public:
    void* Relay();  // compared: 0x915fe0
    Related* GetRelated();
};
