// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12c9340: GUESS(low) STANDIN
// DeletingLeaf12c9340Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12c9340Base
{
public:
    virtual ~DeletingLeaf12c9340Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12c9340 : public DeletingLeaf12c9340Base
{
public:
    explicit DeletingLeaf12c9340(void (*fn)());
    ~DeletingLeaf12c9340() override = default;  // compared: 0x12c9340 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12c9340) == 16, "size observed from the sized delete argument");
