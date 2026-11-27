// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSStoryEventManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function533200: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// StoryEntry533200, HashStoryKey: GUESS(low) STANDIN; story-event hash table
struct StoryEntry533200 { unsigned key; unsigned value; StoryEntry533200* next; };
extern "C" void HashStoryKey(unsigned*, unsigned);

class BGSStoryEventManager
{
public:
    std::uint8_t unknown00[0x24];
    unsigned capacity;
    std::uint64_t unknown28;
    StoryEntry533200* sentinel;
    std::uint64_t unknown38;
    StoryEntry533200* entries;

    unsigned Function533200(unsigned key);
};
