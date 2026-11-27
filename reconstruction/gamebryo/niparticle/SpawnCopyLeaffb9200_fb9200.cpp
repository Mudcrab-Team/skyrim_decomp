// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfb9200 SpawnCopyLeaffb9200::CopyMembers
#include "SpawnCopyLeaffb9200_fb9200.h"

void SpawnCopyLeaffb9200::CopyMembers(SpawnCopyLeaffb9200* destination, SpawnCloneProcess& process)
{
    SpawnCopyBase::CopyMembers(destination, process);
    destination->generations = generations;
    destination->fraction = fraction;
    destination->minimum = minimum;
    destination->maximum = maximum;
    destination->speedVariance = speedVariance;
    destination->directionVariance = directionVariance;
    destination->lifetime = lifetime;
    destination->lifetimeVariance = lifetimeVariance;
}
