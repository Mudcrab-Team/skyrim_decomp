// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESDialoguePackageData: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// ~TESDialoguePackageData: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// PackageDataBase: GUESS(low) STANDIN; package-data base interface
class PackageDataBase { public: virtual ~PackageDataBase() {} };
// Owned4a0080: GUESS(low) STANDIN; virtually owned package state
struct Owned4a0080 { virtual ~Owned4a0080(); };

class TESDialoguePackageData : public PackageDataBase
{
public:
    std::uint8_t unknown08[16];
    Owned4a0080* owned;

     ~TESDialoguePackageData() override;
};
