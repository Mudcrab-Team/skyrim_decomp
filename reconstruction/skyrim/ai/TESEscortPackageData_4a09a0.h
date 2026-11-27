// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESEscortPackageData: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// ~TESEscortPackageData: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// PackageDataBase: GUESS(low) STANDIN; package-data base interface
class PackageDataBase { public: virtual ~PackageDataBase() {} };
// Owned4a09a0: GUESS(low) STANDIN; virtually owned package state
struct Owned4a09a0 { virtual ~Owned4a09a0(); };

class TESEscortPackageData : public PackageDataBase
{
public:
    Owned4a09a0* owned;

     ~TESEscortPackageData() override;
};
