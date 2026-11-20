// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12adca0: GUESS(low) STANDIN
// DeletingLeaf12adca0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12adca0Base
{
public:
    virtual ~DeletingLeaf12adca0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12adca0 : public DeletingLeaf12adca0Base
{
public:
    explicit DeletingLeaf12adca0(void (*fn)());
    ~DeletingLeaf12adca0() override = default;  // compared: 0x12adca0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12adca0) == 16, "size observed from the sized delete argument");
