// Source exposure: binary-analysis (pinned image listing; CrashLogger PDB name hint).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e8160 ObjectFactoryVisitor1e8160::VisitFactory
// Adapted bodies: none
#include "ObjectFactoryVisitor1e8160.h"

// PDB: the CrashLogger PDB names this ObjectFactoryVisitor::VisitFactory in an anonymous namespace; ObjectFactoryVisitor1e8160 is a stand-in for ObjectFactoryVisitor with a partial layout.
// Forwards factories whose type ID is not 0x6A to the inner visitor.
std::uint32_t ObjectFactoryVisitor1e8160::VisitFactory(Factory1e8160* a_factory)
{
    if (a_factory->GetTypeId() != 0x6A) {
        return innerVisitor->Visit(a_factory);
    }
    return 1u;
}
