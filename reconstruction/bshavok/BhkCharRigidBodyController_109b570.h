// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original partial layouts from the rigid body support path.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// bhkCharRigidBodyController, bhkCharacterRigidBody, hkpCharacterRigidBody, ahkpWorld, bhkWorld, hkStepInfo, hkpSurfaceInfo: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// hkpSurfaceInfo::surfaceNormal, ahkpWorld::userData, bhkRefObject::referencedObject: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// CheckSupportImpl, CheckSupport, GetWorld1, GetWorld2, supportNorm, stepInfo, surfaceInfo, charRigidBody: OBSERVED
// WorldSource, WorldSourceVTable, CharacterRigidBodyVTable, FetchWorld, ReadLock, ReadUnlock: GUESS(low)
#pragma once

#include <cstdint>

struct ahkpWorld;
struct WorldSource;
struct hkpCharacterRigidBody;

struct WorldSourceVTable
{
    std::uint8_t leadingSlots[0x138];
    ahkpWorld* (*GetWorld1)(WorldSource*);
    ahkpWorld* (*GetWorld2)(WorldSource*);
};

struct WorldSource
{
    const WorldSourceVTable* vtable;
};

struct bhkWorld : WorldSource
{
    void ReadLock();
    void ReadUnlock();
};

struct ahkpWorld
{
    std::uint8_t unknown00[0x430];
    bhkWorld* userData;
};

struct hkStepInfo
{
    float startTime;
    float endTime;
    float deltaTime;
    float invDeltaTime;
};

struct hkVector4
{
    float values[4];
};

struct hkpSurfaceInfo
{
    std::uint8_t unknown00[0x10];
    hkVector4 surfaceNormal;
    std::uint8_t unknown20[0x20];
};

struct CharacterRigidBodyVTable
{
    std::uint8_t leadingSlots[0x18];
    void (*CheckSupport)(hkpCharacterRigidBody*, const hkStepInfo&, hkpSurfaceInfo&);
};

struct hkpCharacterRigidBody
{
    const CharacterRigidBodyVTable* vtable;
};

struct bhkCharacterRigidBody : WorldSource
{
    ahkpWorld* FetchWorld(hkpCharacterRigidBody*& body);

    std::uint8_t unknown08[8];
    hkpCharacterRigidBody* referencedObject;
};

// BhkCharRigidBodyController: STANDIN EXE_RTTI
// Partial layout of bhkCharRigidBodyController for the support entry.
class BhkCharRigidBodyController
{
public:
    void CheckSupportImpl();

private:
    std::uint8_t unknown00[0x80];
    hkStepInfo stepInfo;
    std::uint8_t unknown90[0x80];
    hkVector4 supportNorm;
    std::uint8_t unknown120[0x80];
    hkpSurfaceInfo surfaceInfo;
    std::uint8_t unknown1E0[0x160];
    bhkCharacterRigidBody charRigidBody;
};
