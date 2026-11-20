// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12c9630: GUESS(low) STANDIN
// DeletingLeaf12c9630Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12c9630Base
{
public:
    virtual ~DeletingLeaf12c9630Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12c9630 : public DeletingLeaf12c9630Base
{
public:
    explicit DeletingLeaf12c9630(void (*fn)());
    ~DeletingLeaf12c9630() override = default;  // compared: 0x12c9630 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12c9630) == 16, "size observed from the sized delete argument");
