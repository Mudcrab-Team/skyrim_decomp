// Source exposure: mixed (pinned image listing and sibling hints).
// Code origin: existing sibling-adapted method plus original reconstruction of Function65b6a0.
// Main, Main::WorldRootCamera: SIBLING(fo4-private@1b765c70, author-permission)
// WorldRoot, MainState65b6a0, GetMainState, worldRoot, Function65b6a0, pad, camera, unknown00, flag11D: STANDIN GUESS(low)
#pragma once
#include <cstdint>

struct WorldRoot { std::uint8_t pad[0x128]; void* camera; };
struct MainState65b6a0 { std::uint8_t unknown00[0x11D]; std::uint8_t flag11D; };

extern WorldRoot* worldRoot;
MainState65b6a0* GetMainState();

class Main {
public:
    static void* WorldRootCamera();
    static bool Function65b6a0();
    void Function65c460();
    void* Function65c8f0();
};
