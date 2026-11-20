// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x2dd530 (reconstruction/skyrim_shared/refs/TESObjectREFR_2dd510.cpp); no external declaration or body reused.
// RelayLeaf985330: GUESS(low) STANDIN
// Related, Relay, GetRelated, Step: GUESS(low) STANDIN
#pragma once

class RelayLeaf985330;

class Related
{
public:
    void* Step(RelayLeaf985330* owner);
};

class RelayLeaf985330
{
public:
    void* Relay();  // compared: 0x985330
    Related* GetRelated();
};
