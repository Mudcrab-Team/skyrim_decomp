// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13afe30: GUESS(low) STANDIN
// DeletingLeaf13afe30Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13afe30Base
{
public:
    virtual ~DeletingLeaf13afe30Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13afe30 : public DeletingLeaf13afe30Base
{
public:
    explicit DeletingLeaf13afe30(void (*fn)());
    ~DeletingLeaf13afe30() override = default;  // compared: 0x13afe30 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13afe30) == 16, "size observed from the sized delete argument");
