// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12eece0: GUESS(low) STANDIN
// DeletingLeaf12eece0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12eece0Base
{
public:
    virtual ~DeletingLeaf12eece0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12eece0 : public DeletingLeaf12eece0Base
{
public:
    explicit DeletingLeaf12eece0(void (*fn)());
    ~DeletingLeaf12eece0() override = default;  // compared: 0x12eece0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12eece0) == 16, "size observed from the sized delete argument");
