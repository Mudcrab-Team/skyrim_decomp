// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13afe00: GUESS(low) STANDIN
// DeletingLeaf13afe00Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13afe00Base
{
public:
    virtual ~DeletingLeaf13afe00Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13afe00 : public DeletingLeaf13afe00Base
{
public:
    explicit DeletingLeaf13afe00(void (*fn)());
    ~DeletingLeaf13afe00() override = default;  // compared: 0x13afe00 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13afe00) == 16, "size observed from the sized delete argument");
