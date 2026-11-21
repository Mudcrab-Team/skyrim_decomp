// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x2dd530 (reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp); no external declaration or body reused.
// RelayLeaf6c7b60: GUESS(low) STANDIN
// Related, Relay, GetRelated, Step: GUESS(low) STANDIN
#pragma once

class RelayLeaf6c7b60;

class Related
{
public:
    void* Step(RelayLeaf6c7b60* owner);
};

class RelayLeaf6c7b60
{
public:
    void* Relay();  // compared: 0x6c7b60
    Related* GetRelated();
};
