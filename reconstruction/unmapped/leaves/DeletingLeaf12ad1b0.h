// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12ad1b0: GUESS(low) STANDIN
// DeletingLeaf12ad1b0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12ad1b0Base
{
public:
    virtual ~DeletingLeaf12ad1b0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12ad1b0 : public DeletingLeaf12ad1b0Base
{
public:
    explicit DeletingLeaf12ad1b0(void (*fn)());
    ~DeletingLeaf12ad1b0() override = default;  // compared: 0x12ad1b0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12ad1b0) == 16, "size observed from the sized delete argument");
