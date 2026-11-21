// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original partial layouts from the rigid body support path.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// bhkCharacterController, bhkCharacterRigidBody, hkpCharacterRigidBody, ahkpWorld, bhkWorld, hkStepInfo, hkpSurfaceInfo: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// hkpSurfaceInfo::surfaceNormal, ahkpWorld::userData, bhkRefObject::referencedObject: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// bhkCharacterController::CheckSupportImpl: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// CheckSupport, GetWorld1, GetWorld2, supportNorm, stepInfo, surfaceInfo, charRigidBody: OBSERVED
// WorldSource, WorldSourceVTable, CharacterRigidBodyVTable, GetWorld, ReadLock, ReadUnlock: GUESS(low)
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
    ahkpWorld* GetWorld()
    {
        return vtable->GetWorld1(this);
    }

    std::uint8_t unknown08[8];
    hkpCharacterRigidBody* referencedObject;
};

struct hkTransform;
struct CFilter;

class bhkCharacterController
{
public:
    virtual ~bhkCharacterController();
    virtual void DeleteThis();
    virtual void GetPositionImpl(hkVector4&, bool) const = 0;
    virtual void SetPositionImpl(const hkVector4&, bool, bool) = 0;
    virtual void GetTransformImpl(hkTransform&) const = 0;
    virtual void SetTransformImpl(const hkTransform&) = 0;
    virtual void GetLinearVelocityImpl(hkVector4&) const = 0;
    virtual void SetLinearVelocityImpl(const hkVector4&) = 0;
    virtual void GetCollisionFilterInfo(CFilter&) const = 0;
    virtual void Unk_09() = 0;
    virtual void Unk_0A() = 0;
    virtual void Unk_0B() = 0;
    virtual void Unk_0C() = 0;
    virtual void CheckSupportImpl() = 0;

protected:
    std::uint8_t unknown08[0x78];
    hkStepInfo stepInfo;
    std::uint8_t unknown90[0x80];
    hkVector4 supportNorm;
    std::uint8_t unknown120[0x80];
    hkpSurfaceInfo surfaceInfo;
    std::uint8_t unknown1E0[0x150];
};

// BhkCharRigidBodyController: STANDIN EXE_RTTI
class BhkCharRigidBodyController : public bhkCharacterController
{
public:
    void CheckSupportImpl() override;

private:
    std::uint8_t listenerBase[0x10];
    bhkCharacterRigidBody charRigidBody;
};
