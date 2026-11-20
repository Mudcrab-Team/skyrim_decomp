// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf129a400: GUESS(low) STANDIN
// DeletingLeaf129a400Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf129a400Base
{
public:
    virtual ~DeletingLeaf129a400Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf129a400 : public DeletingLeaf129a400Base
{
public:
    explicit DeletingLeaf129a400(void (*fn)());
    ~DeletingLeaf129a400() override = default;  // compared: 0x129a400 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf129a400) == 16, "size observed from the sized delete argument");
