// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sky: EXE_RTTI
// SkyLevel, SkyInner, SkyRoot, root, inner, level, result, GetResult: GUESS(low)
// GetResult signature: GUESS(low); const, void* return and no arguments are inferred
#pragma once
#include <cstdint>
struct SkyLevel { std::uint8_t unk00[0x20]; void* result; };
struct SkyInner { std::uint8_t unk00[0x8d0]; SkyLevel* level; };
struct SkyRoot { std::uint8_t unk00[0x48]; SkyInner* inner; };
extern SkyRoot* root;
class Sky { public: void* GetResult() const; };
