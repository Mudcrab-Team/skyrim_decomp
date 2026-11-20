// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13a4eb0: GUESS(low) STANDIN
// DeletingLeaf13a4eb0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13a4eb0Base
{
public:
    virtual ~DeletingLeaf13a4eb0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13a4eb0 : public DeletingLeaf13a4eb0Base
{
public:
    explicit DeletingLeaf13a4eb0(void (*fn)());
    ~DeletingLeaf13a4eb0() override = default;  // compared: 0x13a4eb0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13a4eb0) == 16, "size observed from the sized delete argument");
