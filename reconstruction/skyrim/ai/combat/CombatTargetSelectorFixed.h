// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Function862b50: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatTargetSelector.cpp:134
// CombatTargetSelectorFixed, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
#pragma once
class CombatObjectBase { public: static unsigned int GenerateClassType(const char*); };
class CombatTargetSelectorFixed {
public:
    static unsigned int GetClassType();
    unsigned int* Function862b50(unsigned int* out) const;
private:
    char _pad_0[0x18];
    unsigned int data;
};
