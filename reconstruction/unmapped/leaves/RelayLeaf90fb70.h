// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x2dd530 (reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp); no external declaration or body reused.
// RelayLeaf90fb70: GUESS(low) STANDIN
// Related, Relay, GetRelated, Step: GUESS(low) STANDIN
#pragma once

class RelayLeaf90fb70;

class Related
{
public:
    void* Step(RelayLeaf90fb70* owner);
};

class RelayLeaf90fb70
{
public:
    void* Relay();  // compared: 0x90fb70
    Related* GetRelated();
};
