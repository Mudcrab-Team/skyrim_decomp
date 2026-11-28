// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x44ee90 BGSPackageData44ee90::IsNotEqual
#include "BGSPackageData44ee90_44ee90.h"

// Compares the masked pointer/tag word and value field against two dynamic_cast views of other.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool BGSPackageData44ee90::IsNotEqual(IPackageData* other) const
{
    PackageDataPrimary44ee90* primary = dynamic_cast<PackageDataPrimary44ee90*>(other);
    if (!primary)
    {
        return true;
    }
    if (((primary->firstBits ^ unk08) & ~std::uint64_t(3)) != 0)
    {
        return true;
    }
    PackageDataSecondary44ee90* secondary = dynamic_cast<PackageDataSecondary44ee90*>(other);
    if (!secondary)
    {
        return true;
    }
    if (unk10 != secondary->secondValue)
    {
        return true;
    }
    return false;
}
