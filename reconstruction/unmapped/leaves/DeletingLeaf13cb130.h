// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13cb130: GUESS(low) STANDIN
// DeletingLeaf13cb130Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13cb130Base
{
public:
    virtual ~DeletingLeaf13cb130Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13cb130 : public DeletingLeaf13cb130Base
{
public:
    explicit DeletingLeaf13cb130(void (*fn)());
    ~DeletingLeaf13cb130() override = default;  // compared: 0x13cb130 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13cb130) == 16, "size observed from the sized delete argument");
