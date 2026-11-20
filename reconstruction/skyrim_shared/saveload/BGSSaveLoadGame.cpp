// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// IsFormIDInUse: Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadGame.cpp:157
// GetChange: Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadGame.cpp:115
// BGSSaveLoadGame, BGSSaveLoadGame::IsFormIDInUse, BGSSaveLoadGame::GetChange: SIBLING(fo4-private@1b765c70, author-permission)
// TESForm, ChangeMap, MusicCondition, Player, musicPlayer, unknown00, unknown10, formID, changes, conditions: STANDIN GUESS(low)
// 0x618130 BGSSaveLoadGame::IsFormIDInUse
// 0x616dc0 BGSSaveLoadGame::GetChange
#include "BGSSaveLoadGame.h"

bool BGSSaveLoadGame::IsFormIDInUse(unsigned int id) const { return changes->HasChanges(id); }
bool BGSSaveLoadGame::GetChange(TESForm* form, unsigned int flags) const { return changes->CheckChangeFlags(form->formID, flags); }
