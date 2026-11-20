// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12c9900: GUESS(low) STANDIN
// DeletingLeaf12c9900Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12c9900Base
{
public:
    virtual ~DeletingLeaf12c9900Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12c9900 : public DeletingLeaf12c9900Base
{
public:
    explicit DeletingLeaf12c9900(void (*fn)());
    ~DeletingLeaf12c9900() override = default;  // compared: 0x12c9900 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12c9900) == 16, "size observed from the sized delete argument");
