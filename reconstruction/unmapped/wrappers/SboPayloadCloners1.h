// Source exposure: mixed (pinned image, RTTI and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original reconstruction of copyable callable construction.
// SboPayloadCloners1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; wrapper names and capture identities inferred.
// Adapted bodies: none
#pragma once
#include "CopyableCallable.h"

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);

struct SboPayloadCloners1
{
    template <class Capture>
    static bnet_callable::CopyableCallable<Capture>* Clone(const Capture& source);
};
