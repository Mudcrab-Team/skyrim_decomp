// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// ActorValueInfo443320, ActorValueTable443320, g_actorValueTable443320, Function443320, unk00, name, entries, _stricmp, lhs, rhs: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __cdecl _stricmp(const char* lhs, const char* rhs);

struct ActorValueInfo443320
{
    std::uint64_t unk00[0x0A];  // 0x00
    const char* name;           // 0x50
};
static_assert(offsetof(ActorValueInfo443320, name) == 0x50, "ActorValueInfo443320 name offset");

struct ActorValueTable443320
{
    std::uint64_t unk00;                 // 0x00
    ActorValueInfo443320* entries[164];  // 0x08
};
static_assert(offsetof(ActorValueTable443320, entries) == 0x08, "ActorValueTable443320 entries offset");

extern ActorValueTable443320* g_actorValueTable443320;

std::int32_t Function443320(const char* name);
