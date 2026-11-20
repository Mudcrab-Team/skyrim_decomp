// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12fa820: GUESS(low) STANDIN
// DeletingLeaf12fa820Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12fa820Base
{
public:
    virtual ~DeletingLeaf12fa820Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12fa820 : public DeletingLeaf12fa820Base
{
public:
    explicit DeletingLeaf12fa820(void (*fn)());
    ~DeletingLeaf12fa820() override = default;  // compared: 0x12fa820 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12fa820) == 16, "size observed from the sized delete argument");
