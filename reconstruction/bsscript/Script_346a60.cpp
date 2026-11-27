// Source exposure: mixed
// Code origin: original reconstruction from the pinned image listing, shaped after the sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x346a60 Script::~Script
// Adapted bodies: Script::~Script delegates to complete cleanup, corresponding to the destructor body in momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesscript.cpp.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesscript.cpp:333
#include "Script_346a60.h"

// The constructor emits the vftable and its deleting destructor.
// Member cleanup belongs to the complete destructor in the original image.
Script::Script() = default;
