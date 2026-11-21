// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf14826f0: GUESS(low) STANDIN
// DeletingLeaf14826f0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf14826f0Base
{
public:
    virtual ~DeletingLeaf14826f0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf14826f0 : public DeletingLeaf14826f0Base
{
public:
    explicit DeletingLeaf14826f0(void (*fn)());
    ~DeletingLeaf14826f0() override = default;  // compared: 0x14826f0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf14826f0) == 16, "size observed from the sized delete argument");
