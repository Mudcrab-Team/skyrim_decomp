// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the listing; names from the header.
// Adapted bodies: none
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatTargetSelector.cpp:134
// CombatTargetSelectorFixed, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x862b50 CombatTargetSelectorFixed::Function862b50
#pragma once
class CombatObjectBase { public: static unsigned int GenerateClassType(const char*); };
class CombatTargetSelectorFixed
{
public:
    static unsigned int GetClassType();
    unsigned int* Function862b50(unsigned int* a_out);

private:
    void* unk00;        // 00 (unknown, not accessed here)
    void* unk08;        // 08 (unknown, not accessed here)
    void* unk10;        // 10 (unknown, not accessed here)
    unsigned int m_unk18;  // 18 (name unknown)
};
