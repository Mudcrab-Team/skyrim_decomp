// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x44ee50 BGSPackageData44ee50::Assign
#include "BGSPackageData44ee50_44ee50.h"

// Copies the source value when the input package data converts to PackageDataSource44ee50.
void BGSPackageData44ee50::Assign(IPackageData* source)
{
    PackageDataSource44ee50* castSource = dynamic_cast<PackageDataSource44ee50*>(source);
    if (castSource)
    {
        value = castSource->sourceValue;
    }
}
