// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13b3ce0: GUESS(low) STANDIN
// DeletingLeaf13b3ce0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13b3ce0Base
{
public:
    virtual ~DeletingLeaf13b3ce0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13b3ce0 : public DeletingLeaf13b3ce0Base
{
public:
    explicit DeletingLeaf13b3ce0(void (*fn)());
    ~DeletingLeaf13b3ce0() override = default;  // compared: 0x13b3ce0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13b3ce0) == 16, "size observed from the sized delete argument");
