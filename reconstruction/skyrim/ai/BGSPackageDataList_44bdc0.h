// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSPackageDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function44bdc0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// PackageValue: GUESS(low) STANDIN; package-owned polymorphic data
struct PackageValue { virtual ~PackageValue(); };

class BGSPackageDataList
{
public:
    PackageValue** values;
    unsigned char* tags;
    unsigned short count;

    void Function44bdc0(unsigned char tag);
};
