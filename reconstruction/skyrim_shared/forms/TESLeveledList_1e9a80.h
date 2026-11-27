// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESLeveledList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1e9a80: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Extra1e9a80, Entry1e9a80, Entries1e9a80: GUESS(low) STANDIN; leveled-list records
struct Extra1e9a80 { std::uint8_t unknown00[24]; };
struct Entry1e9a80 { void* form; unsigned count; unsigned unknown0c; Extra1e9a80 extra; };
struct Entries1e9a80 { std::uint64_t unknown00; Entry1e9a80* data; std::uint64_t unknown10; unsigned count; };

class TESLeveledList
{
public:
    void Add(void*, unsigned, const Extra1e9a80*);

    void Function1e9a80(const Entries1e9a80* source);
};
