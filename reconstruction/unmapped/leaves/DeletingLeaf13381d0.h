// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13381d0: GUESS(low) STANDIN
// DeletingLeaf13381d0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13381d0Base
{
public:
    virtual ~DeletingLeaf13381d0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13381d0 : public DeletingLeaf13381d0Base
{
public:
    explicit DeletingLeaf13381d0(void (*fn)());
    ~DeletingLeaf13381d0() override = default;  // compared: 0x13381d0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13381d0) == 16, "size observed from the sized delete argument");
