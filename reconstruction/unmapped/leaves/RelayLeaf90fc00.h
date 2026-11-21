// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x2dd530 (reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp); no external declaration or body reused.
// RelayLeaf90fc00: GUESS(low) STANDIN
// Related, Relay, GetRelated, Step: GUESS(low) STANDIN
#pragma once

class RelayLeaf90fc00;

class Related
{
public:
    void* Step(RelayLeaf90fc00* owner);
};

class RelayLeaf90fc00
{
public:
    void* Relay();  // compared: 0x90fc00
    Related* GetRelated();
};
