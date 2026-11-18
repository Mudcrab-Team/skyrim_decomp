// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// ConsoleNativeUIMenu::ProcessMessage: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Interface/Menus/ConsoleNativeUIMenu.cpp:18
// ConsoleNativeUIMenu, ConsoleNativeUIMenu::ProcessMessage: GUESS(low)
// ConsoleNativeUIMenu fields: STANDIN GUESS(low)
// 0x90f610 ConsoleNativeUIMenu::ProcessMessage
#include "ConsoleNativeUIMenu.h"
int ConsoleNativeUIMenu::ProcessMessage(Message& message) { if (message.type != 6 || detected) return 0; Event* event = message.data->event; if (event->type != 6 || event->code != 16) return 0; detected = true; return 2; }
