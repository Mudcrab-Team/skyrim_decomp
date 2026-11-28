// Source exposure: binary-analysis (pinned image listing; CrashLogger PDB name hint).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e81b0 ObjectTypeFinder1e81b0::VisitFactory
// Adapted bodies: none
#include "ObjectTypeFinder1e81b0.h"

// PDB: the CrashLogger PDB names this ObjectTypeFinder::VisitFactory in an anonymous namespace; ObjectTypeFinder1e81b0 is a stand-in for ObjectTypeFinder with a partial layout.
// Captures the factory matching targetType and stops iteration when found.
std::uint32_t ObjectTypeFinder1e81b0::VisitFactory(Factory1e81b0* a_factory)
{
    if (a_factory->GetTypeId() == targetType) {
        foundFactory = a_factory;
        return 0u;
    }
    return 1u;
}
