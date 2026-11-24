// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); placeholder class, a view of the movement-controller member only
// Character::QueryMovementInterfaceState: GUESS(low)
// movementController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's Actor member at 0x148, 8 bytes later in this build
// BSTSmartPointer, MovementControllerNPC, IMovementControllerRegisterInterface, IMovementInterface: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the pointer and the slots the body calls
// BSTSmartPointer::get, BSTSmartPointer::_ptr, IMovementControllerRegisterInterface::Unk_01, IMovementControllerRegisterInterface::Unk_02, IMovementControllerRegisterInterface::Unk_03: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares Unk_03 void, here it takes an interface id and returns an interface
// IMovementInterface::QuerySlot01, IMovementInterface::QuerySlot02, IMovementInterface::QueryState: GUESS(low); slots of the returned interface, slot 3 a bool query
// InterfaceId, movementInterfaceId: GUESS(low); the id object at RVA 0x3350b18 passed to the lookup
#pragma once

#include <cstdint>
#include <cstddef>

struct InterfaceId;
extern const InterfaceId movementInterfaceId;

class IMovementInterface
{
public:
    virtual ~IMovementInterface();  // 00
    virtual void QuerySlot01();     // 01
    virtual void QuerySlot02();     // 02
    virtual bool QueryState();      // 03
};

class IMovementControllerRegisterInterface
{
public:
    virtual ~IMovementControllerRegisterInterface();                // 00
    virtual void                Unk_01();                           // 01
    virtual void                Unk_02();                           // 02
    virtual IMovementInterface* Unk_03(const InterfaceId* a_id);    // 03
};

class MovementControllerNPC : public IMovementControllerRegisterInterface
{
};

template <class T>
class BSTSmartPointer
{
public:
    T* get() const { return _ptr; }

    T* _ptr;
};

class Character
{
public:
    bool QueryMovementInterfaceState();  // compared: 0x6af050

    std::uint8_t                           pad00[0x150];
    BSTSmartPointer<MovementControllerNPC> movementController;  // 150
};
