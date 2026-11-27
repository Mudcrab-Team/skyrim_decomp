// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ActorPackage: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6e0db0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Package6e0db0, Override6e0db0: GUESS(low) STANDIN; package defaults and overrides
struct Package6e0db0 { std::uint8_t unknown00[0x20]; unsigned flags; unsigned unknown24; std::uint16_t flags2; std::uint8_t GetMode(); };
struct Override6e0db0 { unsigned set; unsigned clear; std::uint16_t set2; std::uint16_t clear2; std::uint8_t mode; };

class ActorPackage
{
public:
    std::uint64_t unknown00;
    Package6e0db0* package;
    std::uint8_t unknown10[0x14];
    unsigned flags;
    std::uint16_t flags2;
    std::uint8_t unknown2a;
    std::uint8_t mode;

    void Function6e0db0(const Override6e0db0* change);
};
