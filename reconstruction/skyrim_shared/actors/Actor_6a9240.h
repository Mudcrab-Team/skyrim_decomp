// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6a9240: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Request6a9240, Reader6a9240, Provider6a9240, Manager6a9240, manager6a9240, readKey6a9240: GUESS(low) STANDIN; actor request interfaces
struct Request6a9240 { std::uint8_t unknown00[0x10]; void* input; void* output; };
struct Reader6a9240 { virtual ~Reader6a9240(); virtual void Read(void**,void**); };
struct Provider6a9240 { virtual ~Provider6a9240(); virtual void Unk01(); virtual void Unk02(); virtual Reader6a9240* Find(const void*); };
struct Manager6a9240 { void Release(void*,unsigned); };
extern Manager6a9240* manager6a9240;
extern unsigned char readKey6a9240;

class Actor
{
public:
    std::uint8_t unknown00[0x150];
    Provider6a9240* provider;

    int Function6a9240(Request6a9240* request);
};
