// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetObjectType: SIBLING(fo4-private@1b765c70, author-permission); src/Game/AI/Combat/CombatTargetSelector.cpp:102; adapted behavior.
// Semantic names and signatures: GUESS(low); static type-name literal and generator inferred from target and related reconstructions.
#pragma once
class CombatObjectBase { public: static unsigned int GenerateClassType(const char*); };
class CombatTargetSelector { public: unsigned int GetObjectType() const; };
