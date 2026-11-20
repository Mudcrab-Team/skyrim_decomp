// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1282ac0: GUESS(low) STANDIN
// DeletingLeaf1282ac0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1282ac0Base
{
public:
    virtual ~DeletingLeaf1282ac0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1282ac0 : public DeletingLeaf1282ac0Base
{
public:
    explicit DeletingLeaf1282ac0(void (*fn)());
    ~DeletingLeaf1282ac0() override = default;  // compared: 0x1282ac0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1282ac0) == 16, "size observed from the sized delete argument");
