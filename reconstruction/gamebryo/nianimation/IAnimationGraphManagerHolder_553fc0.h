// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layout from the animation update entry.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// IAnimationGraphManagerHolder, BSAnimationGraphManager, BSAnimationUpdateData, UpdateAnimationGraphManager, GetAnimationGraphManagerImpl, Unk_0E: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// GraphManagerRef, AnimationHolderVTable, skipUpdateCheck, Update: GUESS(low)
#pragma once

#include <cstdint>

struct BSAnimationUpdateData
{
    std::uint8_t unknown00[0x2a];
    bool skipUpdateCheck;
};

class BSAnimationGraphManager
{
public:
    virtual ~BSAnimationGraphManager();
    void Update(const BSAnimationUpdateData& data);

    volatile long refCount;
};

struct GraphManagerRef;
class IAnimationGraphManagerHolder;

struct AnimationHolderVTable
{
    std::uint8_t unknown00[0x10];
    bool (*GetAnimationGraphManagerImpl)(IAnimationGraphManagerHolder*, GraphManagerRef&);
    std::uint8_t unknown18[0x58];
    bool (*Unk_0E)(IAnimationGraphManagerHolder*);
};

class IAnimationGraphManagerHolder
{
public:
    bool UpdateAnimationGraphManager(const BSAnimationUpdateData& data);

private:
    const AnimationHolderVTable* vtable;
};
