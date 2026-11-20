// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// Main, Main::WorldRootCamera: GUESS(low)
// Main fields: STANDIN GUESS(low)
// Supporting types: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct WorldRoot { std::uint8_t pad[0x128]; void* camera; };
extern WorldRoot* worldRoot;
class Main {
public: static void* WorldRootCamera();
private: 
};
