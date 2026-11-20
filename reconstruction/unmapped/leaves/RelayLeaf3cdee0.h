// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x2dd530 (reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp); no external declaration or body reused.
// RelayLeaf3cdee0: GUESS(low) STANDIN
// Related, Relay, GetRelated, Step: GUESS(low) STANDIN
#pragma once

class RelayLeaf3cdee0;

class Related
{
public:
    void* Step(RelayLeaf3cdee0* owner);
};

class RelayLeaf3cdee0
{
public:
    void* Relay();  // compared: 0x3cdee0
    Related* GetRelated();
};
