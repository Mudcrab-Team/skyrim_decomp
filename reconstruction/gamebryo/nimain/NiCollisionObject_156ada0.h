// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiStream, NiRefObject, NiObject, NiCollisionObject: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream::ReadLinkID, NiObject::LinkObject, NiCollisionObject::LinkObject: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::unk00, NiCollisionObject::sceneObject: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiObject;

class NiStream
{
public:
    NiObject* ReadLinkID();
};

class NiRefObject
{
public:
    std::uint8_t unk00[0x10];
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
    void LinkObject(NiStream& a_stream);
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class NiCollisionObject : public NiObject
{
public:
    void LinkObject(NiStream& a_stream);

    NiObject* sceneObject;
};
static_assert(offsetof(NiCollisionObject, sceneObject) == 0x10, "sceneObject offset");
