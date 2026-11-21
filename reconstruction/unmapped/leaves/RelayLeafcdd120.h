// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x2dd530 (reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp); no external declaration or body reused.
// RelayLeafcdd120: GUESS(low) STANDIN
// Related, Relay, GetRelated, Step: GUESS(low) STANDIN
#pragma once

class RelayLeafcdd120;

class Related
{
public:
    void* Step(RelayLeafcdd120* owner);
};

class RelayLeafcdd120
{
public:
    void* Relay();  // compared: 0xcdd120
    Related* GetRelated();
};
