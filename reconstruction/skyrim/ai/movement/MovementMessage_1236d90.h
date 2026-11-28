// Source exposure: mixed (pinned image and cited public names).
// Code origin: reconstruction using cited names and stand-in layouts; see Adapted bodies.
// Adapted bodies: SmartPathPtr::~SmartPathPtr, treated as adapted: it has the shape of NiPointer::~NiPointer, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// MovementMessage: CRASHLOGGER_PDB(59818@2026.10.24)
// MovementMessageNewPath, MovementPathRef, SmartPathPtr, refCount, ptr, DecRef, unk08, path: GUESS(low) STANDIN
// Note: 0x1236d90 is a destructor releasing a ref-counted member, not a constructor; MovementMessage is the base class.
#pragma once

#include <cstdint>
#include <intrin.h>

class MovementPathRef
{
public:
    virtual ~MovementPathRef();

    void DecRef()
    {
        // hot path: atomic intrusive reference count release
        if (_InterlockedExchangeAdd(&refCount, -1) == 1)
        {
            delete this;
        }
    }

    // volatile: intrusive reference count is modified atomically across threads
    volatile long refCount;  // 08
};

struct SmartPathPtr
{
    ~SmartPathPtr()
    {
        MovementPathRef* p = ptr;
        if (p)
        {
            // hot path: atomic intrusive reference count release
            if (_InterlockedExchangeAdd(&p->refCount, -1) == 1)
            {
                delete p;
            }
        }
    }

    MovementPathRef* ptr;  // 00
};

class MovementMessage
{
public:
    virtual ~MovementMessage();

    std::uint64_t unk08;  // 08
};
static_assert(sizeof(MovementMessage) == 0x10, "MovementMessage size");

class MovementMessageNewPath : public MovementMessage
{
public:
    ~MovementMessageNewPath() override;

    SmartPathPtr path;  // 10
};
static_assert(sizeof(MovementMessageNewPath) == 0x18, "MovementMessageNewPath size");
