// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1462ac0: GUESS(low) STANDIN
// DeletingLeaf1462ac0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1462ac0Base
{
public:
    virtual ~DeletingLeaf1462ac0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1462ac0 : public DeletingLeaf1462ac0Base
{
public:
    explicit DeletingLeaf1462ac0(void (*fn)());
    ~DeletingLeaf1462ac0() override = default;  // compared: 0x1462ac0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1462ac0) == 16, "size observed from the sized delete argument");
