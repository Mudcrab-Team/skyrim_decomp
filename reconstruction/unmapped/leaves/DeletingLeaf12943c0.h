// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12943c0: GUESS(low) STANDIN
// DeletingLeaf12943c0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12943c0Base
{
public:
    virtual ~DeletingLeaf12943c0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12943c0 : public DeletingLeaf12943c0Base
{
public:
    explicit DeletingLeaf12943c0(void (*fn)());
    ~DeletingLeaf12943c0() override = default;  // compared: 0x12943c0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12943c0) == 16, "size observed from the sized delete argument");
