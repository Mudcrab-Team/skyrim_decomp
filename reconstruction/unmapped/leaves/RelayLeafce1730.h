// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x2dd530 (reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp); no external declaration or body reused.
// RelayLeafce1730: GUESS(low) STANDIN
// Related, Relay, GetRelated, Step: GUESS(low) STANDIN
#pragma once

class RelayLeafce1730;

class Related
{
public:
    void* Step(RelayLeafce1730* owner);
};

class RelayLeafce1730
{
public:
    void* Relay();  // compared: 0xce1730
    Related* GetRelated();
};
