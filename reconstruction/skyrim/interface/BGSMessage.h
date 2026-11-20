// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitializeData: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMessage.cpp:132
// BGSMessage, BGSMessage::InitializeData: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, icon, owner, unknown50, flags, displayTime: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class BGSMessage { public: void InitializeData(); private: std::uint64_t unknown00[8]; void* icon; void* owner; std::uint64_t unknown50[2]; std::uint32_t flags; std::uint32_t displayTime; };
