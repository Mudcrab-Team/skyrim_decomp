// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSParentVelocityModifier: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// BSParentVelocityModifier: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>
#include <cstring>

// Base1001a30: GUESS(low) STANDIN; base subobject with unobserved members
// defaults1001a30: GUESS(low); default spatial value
extern float defaults1001a30[3];
class Base1001a30
{
public:
    Base1001a30();
    virtual ~Base1001a30();
    std::uint8_t unknown08[16];
    unsigned kind;
    std::uint8_t unknown1c[20];
};

class BSParentVelocityModifier : public Base1001a30
{
public:
    unsigned flags;
    unsigned unknown34;
    unsigned count;
    struct Vectors { float first[3]; float second[3]; } vectors;

     BSParentVelocityModifier();
};
