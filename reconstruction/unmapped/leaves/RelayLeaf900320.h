// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x2dd530 (reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp); no external declaration or body reused.
// RelayLeaf900320: GUESS(low) STANDIN
// Related, Relay, GetRelated, Step: GUESS(low) STANDIN
#pragma once

class RelayLeaf900320;

class Related
{
public:
    void* Step(RelayLeaf900320* owner);
};

class RelayLeaf900320
{
public:
    void* Relay();  // compared: 0x900320
    Related* GetRelated();
};
