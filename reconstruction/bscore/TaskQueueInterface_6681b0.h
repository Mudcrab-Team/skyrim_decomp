// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TaskQueueInterface: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6681b0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>

// Handle6681b0, Actor6681b0, Value6681b0, Task6681b0: GUESS(low) STANDIN; retained actor task payload
struct Handle6681b0 { virtual ~Handle6681b0(); virtual unsigned Get(); };
struct Actor6681b0 { std::uint8_t unknown00[0x28]; long references; std::uint8_t unknown2c[0x94]; Handle6681b0 handle; };
struct Value6681b0 { virtual ~Value6681b0(); virtual void* Get(); };
struct Task6681b0 { unsigned opcode,unknown04; unsigned handle,unknown0c; void* value; std::uint8_t unknown18[0x68]; };

class TaskQueueInterface
{
public:
    void Enqueue(Task6681b0*);

    void Function6681b0(Actor6681b0* actor,Value6681b0* value);
};
