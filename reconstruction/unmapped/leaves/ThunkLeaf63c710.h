// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x146720 (reconstruction/skyrim_shared/forms/TESFullName.cpp); no external declaration or body reused.
// ThunkLeaf63c710: GUESS(low) STANDIN
// Field, Get, field08, unknown00, Forward: GUESS(low) STANDIN
#pragma once

class Field
{
public:
    void* Get() const;
};

class ThunkLeaf63c710
{
public:
    void* Forward() const;  // compared: 0x63c710
    unsigned char unknown00[8];
    Field field08;
};
