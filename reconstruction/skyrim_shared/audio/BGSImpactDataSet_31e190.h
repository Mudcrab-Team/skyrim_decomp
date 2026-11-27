// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSImpactDataSet: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// ~BGSImpactDataSet: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Form31e190, Component31e190, ImpactStorage31e190: GUESS(low) STANDIN; form and component bases
struct Form31e190 { virtual ~Form31e190(); std::uint8_t unknown08[0x18]; };
struct Component31e190 { virtual ~Component31e190() {} std::uint64_t unknown08; };
struct ImpactStorage31e190 { ~ImpactStorage31e190(); };

class BGSImpactDataSet : public Form31e190, public Component31e190
{
public:
    ImpactStorage31e190 impacts;

     ~BGSImpactDataSet();
};
