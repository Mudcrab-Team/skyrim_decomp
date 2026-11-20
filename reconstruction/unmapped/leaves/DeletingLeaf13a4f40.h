// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13a4f40: GUESS(low) STANDIN
// DeletingLeaf13a4f40Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13a4f40Base
{
public:
    virtual ~DeletingLeaf13a4f40Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13a4f40 : public DeletingLeaf13a4f40Base
{
public:
    explicit DeletingLeaf13a4f40(void (*fn)());
    ~DeletingLeaf13a4f40() override = default;  // compared: 0x13a4f40 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13a4f40) == 16, "size observed from the sized delete argument");
