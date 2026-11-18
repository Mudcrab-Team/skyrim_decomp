// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// IsFormIDInUse: Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadGame.cpp:157
// GetChange: Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadGame.cpp:115
// BGSSaveLoadGame, BGSSaveLoadGame::IsFormIDInUse, BGSSaveLoadGame::GetChange: SIBLING(fo4-private@1b765c70, author-permission)
// TESForm, ChangeMap, MusicCondition, Player, musicPlayer, unknown00, unknown10, formID, changes, conditions: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct TESForm { std::uint64_t unknown00[2]; std::uint32_t unknown10; std::uint32_t formID; };
class ChangeMap { public: bool HasChanges(unsigned int); bool CheckChangeFlags(unsigned int, unsigned int); };
class BGSSaveLoadGame { public: bool IsFormIDInUse(unsigned int) const; bool GetChange(TESForm*, unsigned int) const; private: std::uint64_t unknown00[102]; ChangeMap* changes; };
