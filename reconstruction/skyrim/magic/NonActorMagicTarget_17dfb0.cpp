// Source exposure: mixed
// Code origin: original reconstruction from the pinned image listing, shaped after the sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x17dfb0 NonActorMagicTarget::~NonActorMagicTarget
// Adapted bodies: NonActorMagicTarget::~NonActorMagicTarget follows momusdigital/fnv_decomp@91e1b6e8 src/fallout/magic/nonactormagictarget.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout/magic/nonactormagictarget.cpp:31
#include "NonActorMagicTarget_17dfb0.h"

// The constructor emits the vftables and their deleting destructor entries.
NonActorMagicTarget::NonActorMagicTarget() = default;

// Cleanup uses the base-class virtual tables.
class __declspec(novtable) NonActorMagicTarget;

NonActorMagicTarget::~NonActorMagicTarget()
{
}
