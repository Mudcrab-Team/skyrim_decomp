// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitializeData: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMessage.cpp:132
// BGSMessage, BGSMessage::InitializeData: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, icon, owner, unknown50, flags, displayTime: STANDIN GUESS(low)
// 0x323dc0 BGSMessage::InitializeData
#include "BGSMessage.h"
void BGSMessage::InitializeData() { flags = 1; icon = nullptr; owner = nullptr; displayTime = 2; }
