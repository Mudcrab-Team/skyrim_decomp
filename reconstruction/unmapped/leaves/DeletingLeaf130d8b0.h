// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf130d8b0: GUESS(low) STANDIN
// DeletingLeaf130d8b0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf130d8b0Base
{
public:
    virtual ~DeletingLeaf130d8b0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf130d8b0 : public DeletingLeaf130d8b0Base
{
public:
    explicit DeletingLeaf130d8b0(void (*fn)());
    ~DeletingLeaf130d8b0() override = default;  // compared: 0x130d8b0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf130d8b0) == 16, "size observed from the sized delete argument");
