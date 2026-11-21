// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13b1eb0: GUESS(low) STANDIN
// DeletingLeaf13b1eb0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13b1eb0Base
{
public:
    virtual ~DeletingLeaf13b1eb0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13b1eb0 : public DeletingLeaf13b1eb0Base
{
public:
    explicit DeletingLeaf13b1eb0(void (*fn)());
    ~DeletingLeaf13b1eb0() override = default;  // compared: 0x13b1eb0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13b1eb0) == 16, "size observed from the sized delete argument");
