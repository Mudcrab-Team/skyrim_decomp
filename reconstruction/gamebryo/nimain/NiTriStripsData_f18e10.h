// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiTriStripsData: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// NiTriStripsData: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Basef18e10: GUESS(low) STANDIN; base subobject with unobserved members
class Basef18e10
{
public:
    Basef18e10();
    virtual ~Basef18e10();
    std::uint8_t unknown08[104];
};

class NiTriStripsData : public Basef18e10
{
public:
    std::uint16_t unknown70;
    std::uint64_t* unknown78;
    std::uint64_t unknown80;

     NiTriStripsData();
};
