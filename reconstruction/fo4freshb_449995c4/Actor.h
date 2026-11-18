// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// Actor, Actor::ForceEditorLocation, Actor::GetEditorLocation, Actor::IsKnockedDown: GUESS(low)
// Actor fields: STANDIN GUESS(low)
#pragma once
#include <cstdint>
// Point3: STANDIN GUESS(low)
struct Point3 { float x, y, z; Point3(float a, float b, float c) : x(a), y(b), z(c) {} Point3(const Point3& other) : x(other.x), y(other.y), z(other.z) {} };
// CombatState, BaseRecord, PowerNode: STANDIN GUESS(low)
struct CombatState { void* group; std::uint8_t pad[0x3b]; bool inactive; };
struct BaseRecord { std::uint8_t pad[0x1c0]; void* actorClass; };
struct PowerNode { void* power; std::uint8_t pad[8]; PowerNode* next; };
class Actor {
public:
    void ForceEditorLocation(void* location); void* GetEditorLocation() const; bool IsKnockedDown() const; void SetCombatGroup(void* group); void* GetCombatGroup() const; bool IsInCombat() const; void* GetClass(); bool IsInCastPowerList(void* power) const; Point3 GetStartingLocation(); Point3 GetStartingAngle();
private:
    std::uint8_t pad[0x40]; BaseRecord* base; std::uint8_t pad48[0x80]; std::uint32_t flags; std::uint8_t gap[0x5c]; Point3 startingLocation; float startingAngle; std::uint8_t gap138[8]; void* editorLocation; std::uint8_t gap148[0x18]; CombatState* combat; std::uint8_t gap168[0x20]; PowerNode* powers;
};
