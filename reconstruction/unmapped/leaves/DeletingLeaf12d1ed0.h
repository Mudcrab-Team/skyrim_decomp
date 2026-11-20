// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12d1ed0: GUESS(low) STANDIN
// DeletingLeaf12d1ed0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12d1ed0Base
{
public:
    virtual ~DeletingLeaf12d1ed0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12d1ed0 : public DeletingLeaf12d1ed0Base
{
public:
    explicit DeletingLeaf12d1ed0(void (*fn)());
    ~DeletingLeaf12d1ed0() override = default;  // compared: 0x12d1ed0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12d1ed0) == 16, "size observed from the sized delete argument");
