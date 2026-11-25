// Source exposure: binary-analysis
// Unlockee5390: GUESS(low) STANDIN; original owner is unknown
// Functionee5390: GUESS(low); provisional entry name
#pragma once
#include <cstdint>
#include <cstddef>
struct LinkBufferee5390 { std::uint64_t unk00; std::uint32_t* links; };
extern __declspec(thread) LinkBufferee5390* streamLinks;

class Unlockee5390 {
public:
    std::uint64_t unk00[68];
    void** objects;
    std::uint64_t unk228;
    std::uint64_t unk230;
    std::uint64_t unk238;
    std::uint64_t unk240;
    std::uint64_t unk248;
    std::uint64_t unk250;
    std::uint64_t unk258;
    std::uint64_t unk260;
    std::uint64_t unk268;
    std::uint64_t unk270;
    std::uint64_t unk278;
    std::uint64_t unk280;
    std::uint64_t unk288;
    std::uint64_t unk290;
    std::uint64_t unk298;
    std::uint64_t unk2a0;
    std::uint32_t nextLink;
    void* Functionee5390();
};
