// Source exposure: binary-analysis
// Unlock11b6ae0: GUESS(low) STANDIN; original owner is unknown
// Function11b6ae0: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
// volatile: lock and reference words are shared with other threads.
class Ref11b6ae0 { public: virtual ~Ref11b6ae0(); volatile long references; };
struct Path11b6ae0 { float x,y,z; std::uint32_t unk0c; void* first; void* second; Ref11b6ae0* owner; std::uint16_t flags; std::uint8_t byte2a, byte2b; };

class Unlock11b6ae0 {
public:
    static Path11b6ae0* Function11b6ae0(Path11b6ae0* out, const Path11b6ae0* source);
};
