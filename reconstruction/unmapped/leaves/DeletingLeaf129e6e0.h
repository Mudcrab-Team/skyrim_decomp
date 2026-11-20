// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf129e6e0: GUESS(low) STANDIN
// DeletingLeaf129e6e0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf129e6e0Base
{
public:
    virtual ~DeletingLeaf129e6e0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf129e6e0 : public DeletingLeaf129e6e0Base
{
public:
    explicit DeletingLeaf129e6e0(void (*fn)());
    ~DeletingLeaf129e6e0() override = default;  // compared: 0x129e6e0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf129e6e0) == 16, "size observed from the sized delete argument");
