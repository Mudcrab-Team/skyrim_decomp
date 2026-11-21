// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf14825a0: GUESS(low) STANDIN
// DeletingLeaf14825a0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf14825a0Base
{
public:
    virtual ~DeletingLeaf14825a0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf14825a0 : public DeletingLeaf14825a0Base
{
public:
    explicit DeletingLeaf14825a0(void (*fn)());
    ~DeletingLeaf14825a0() override = default;  // compared: 0x14825a0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf14825a0) == 16, "size observed from the sized delete argument");
