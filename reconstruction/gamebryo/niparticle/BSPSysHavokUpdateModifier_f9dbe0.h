// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSPSysHavokUpdateModifier: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// BSPSysHavokUpdateModifier: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Basef9dbe0: GUESS(low) STANDIN; base subobject with unobserved members
// defaultNamef9dbe0: GUESS(low); default particle-modifier name
extern const char* defaultNamef9dbe0;
class Basef9dbe0
{
public:
    Basef9dbe0(const char*);
    virtual ~Basef9dbe0();
    std::uint8_t unknown08[64];
};

class BSPSysHavokUpdateModifier : public Basef9dbe0
{
public:
    std::uint64_t unknown48;
    std::uint64_t unknown50;

     BSPSysHavokUpdateModifier();
};
