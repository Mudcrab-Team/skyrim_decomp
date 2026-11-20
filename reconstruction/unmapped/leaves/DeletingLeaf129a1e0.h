// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf129a1e0: GUESS(low) STANDIN
// DeletingLeaf129a1e0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf129a1e0Base
{
public:
    virtual ~DeletingLeaf129a1e0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf129a1e0 : public DeletingLeaf129a1e0Base
{
public:
    explicit DeletingLeaf129a1e0(void (*fn)());
    ~DeletingLeaf129a1e0() override = default;  // compared: 0x129a1e0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf129a1e0) == 16, "size observed from the sized delete argument");
