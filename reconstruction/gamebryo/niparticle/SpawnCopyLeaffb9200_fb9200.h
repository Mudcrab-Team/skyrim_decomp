// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysSpawnModifier, CopyMembers: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

struct SpawnCloneProcess;
struct SpawnCopyBase
{
    void CopyMembers(SpawnCopyBase* destination, SpawnCloneProcess& process);
    std::uint8_t state[0x30];
};
struct SpawnCopyLeaffb9200 : SpawnCopyBase
{
    void CopyMembers(SpawnCopyLeaffb9200* destination, SpawnCloneProcess& process);
    std::uint16_t generations;
    float fraction;
    std::uint16_t minimum;
    std::uint16_t maximum;
    float speedVariance;
    float directionVariance;
    float lifetime;
    float lifetimeVariance;
};
