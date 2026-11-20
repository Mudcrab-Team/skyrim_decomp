// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// Main::WorldRootCamera: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Misc/Main.cpp:137
// Main, Main::WorldRootCamera: GUESS(low)
// Main fields: STANDIN GUESS(low)
// 0x65c480 Main::WorldRootCamera
#include "Main.h"
void* Main::WorldRootCamera() { return worldRoot->camera; }
