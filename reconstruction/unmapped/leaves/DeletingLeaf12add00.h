// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12add00: GUESS(low) STANDIN
// DeletingLeaf12add00Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12add00Base
{
public:
    virtual ~DeletingLeaf12add00Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12add00 : public DeletingLeaf12add00Base
{
public:
    explicit DeletingLeaf12add00(void (*fn)());
    ~DeletingLeaf12add00() override = default;  // compared: 0x12add00 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12add00) == 16, "size observed from the sized delete argument");
