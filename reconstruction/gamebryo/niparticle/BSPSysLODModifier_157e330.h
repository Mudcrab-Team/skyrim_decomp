// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSPSysLODModifier: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// BSPSysLODModifier: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Base157e330: GUESS(low) STANDIN; base subobject with unobserved members
class Base157e330
{
public:
    Base157e330();
    virtual ~Base157e330();
    std::uint8_t unknown08[40];
};

class BSPSysLODModifier : public Base157e330
{
public:
    float first;
    float second;
    float third;
    float fourth;

     BSPSysLODModifier();
};
