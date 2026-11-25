// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSInputDeviceManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioncf9700: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Inputcf9700: GUESS(low) STANDIN; input-device query interface
struct Inputcf9700 { virtual ~Inputcf9700(); virtual void Unk01(); virtual void Unk02(); virtual void Unk03(); virtual void Unk04(); virtual void Unk05(); virtual bool Query(unsigned, void*); };

class BSInputDeviceManager
{
public:
    std::uint8_t unknown00[0x60];
    Inputcf9700* devices[4];

    bool Functioncf9700(int device, unsigned code, void* output);
};
