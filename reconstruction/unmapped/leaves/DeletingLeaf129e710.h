// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf129e710: GUESS(low) STANDIN
// DeletingLeaf129e710Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf129e710Base
{
public:
    virtual ~DeletingLeaf129e710Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf129e710 : public DeletingLeaf129e710Base
{
public:
    explicit DeletingLeaf129e710(void (*fn)());
    ~DeletingLeaf129e710() override = default;  // compared: 0x129e710 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf129e710) == 16, "size observed from the sized delete argument");
