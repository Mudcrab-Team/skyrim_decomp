// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x956600 MagicMenu::~MagicMenu
#include "MagicMenu.h"
MagicMenu::MagicMenu() {}
MagicMenu::~MagicMenu() { InventoryManager->readyForRender=1; DecrementMenuBlur(BlurManager); PopMenuHUD("InventoryMode"); FinishMagicMenu(MenuState,true); }

