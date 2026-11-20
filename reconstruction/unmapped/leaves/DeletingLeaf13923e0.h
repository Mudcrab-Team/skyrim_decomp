// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13923e0: GUESS(low) STANDIN
// DeletingLeaf13923e0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13923e0Base
{
public:
    virtual ~DeletingLeaf13923e0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13923e0 : public DeletingLeaf13923e0Base
{
public:
    explicit DeletingLeaf13923e0(void (*fn)());
    ~DeletingLeaf13923e0() override = default;  // compared: 0x13923e0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13923e0) == 16, "size observed from the sized delete argument");
