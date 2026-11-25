// Source exposure: mixed (community-generated layout and local binary analysis).
// Code origin: original reconstruction; accessed pointer name from community-generated layout.
// ActorKnowledge, detectionState, DetectionState: CRASHLOGGER_PDB(59818@2026.10.24)
// ClearDetectionState: SIBLING(fo4-private@1b765c70, author-permission); name corroborated by project label index.
// refCount, UnknownSlot0, Destroy: GUESS(low); minimal reference-counted stand-in.
// 0x7c4090 ActorKnowledge::ClearDetectionState
#pragma once
#include <cstddef>
#include <cstdint>
class DetectionState
{
public:
    virtual void UnknownSlot0();
    virtual void Destroy();
    long refCount;
};
class ActorKnowledge
{
public:
    void ClearDetectionState();
    std::uint8_t unknown00[0x20];
    DetectionState* detectionState;
};
static_assert(offsetof(ActorKnowledge, detectionState) == 0x20, "detection state offset");
