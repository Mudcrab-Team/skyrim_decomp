// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// ShouldDispelOnDeath: Sibling source: fo4-private@1b765c70 src/Game/Magic/ReanimateEffect.cpp:63
// ReanimateEffect, ReanimateEffect::ShouldDispelOnDeath: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, gettingUp, BaseShouldDispelOnDeath: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class ReanimateEffect { public: bool ShouldDispelOnDeath() const; private: bool BaseShouldDispelOnDeath() const; std::uint64_t unknown00[19]; bool gettingUp; };
