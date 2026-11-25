// Source exposure: binary-analysis (pinned-image observations; community-generated name map).
// Code origin: original partial declaration
// MagicTarget, MagicTarget::GetResistance: CRASHLOGGER_PDB(59818@2026.10.24)
// magicResistance, elementalResistance: GUESS(low); descriptive parameter names
#pragma once
class MagicTarget {
public:
    static float GetResistance(float magicResistance, float elementalResistance);
};
