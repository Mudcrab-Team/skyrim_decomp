// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// QueuedHelmet: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function192880: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Target192880, Queue192880, queue192880: GUESS(low) STANDIN; queued helmet attachment state
struct Target192880 { void Attach(void*,void*,int); };
struct Queue192880 { void Remove(unsigned*); };
extern Queue192880* queue192880;

class QueuedHelmet
{
public:
    std::uint8_t unknown00[0x308];
    Target192880* target;
    void* types[42];
    void* sources[42];
    unsigned id;

    void Function192880();
};
