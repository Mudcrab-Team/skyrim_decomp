// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ActorPackage: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6e0640: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Package6e0640: GUESS(low) STANDIN; package interface
struct Package6e0640 { virtual ~Package6e0640(); virtual void Unk01(); virtual void Unk02(); virtual void Release(); };

class ActorPackage
{
public:
    std::uint8_t unknown00[0x10];
    Package6e0640* package;

    void Function6e0640();
};
