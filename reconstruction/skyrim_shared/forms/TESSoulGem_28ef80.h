// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESSoulGem.cpp:135 (TESSoulGem::GetSoulLevelValue)
// TESSoulGem, GetSoulLevelValue: GUESS(low)
#pragma once
// soul, petty, lesser, common, greater, grand, SOUL_LEVEL: GUESS(low)
enum SOUL_LEVEL { PETTY = 1, LESSER, COMMON, GREATER, GRAND };
class TESSoulGem { public: static unsigned int petty, lesser, common, greater, grand; static unsigned int GetSoulLevelValue(SOUL_LEVEL soul); };
