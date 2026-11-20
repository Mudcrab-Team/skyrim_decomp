// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1392820: GUESS(low) STANDIN
// DeletingLeaf1392820Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1392820Base
{
public:
    virtual ~DeletingLeaf1392820Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1392820 : public DeletingLeaf1392820Base
{
public:
    explicit DeletingLeaf1392820(void (*fn)());
    ~DeletingLeaf1392820() override = default;  // compared: 0x1392820 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1392820) == 16, "size observed from the sized delete argument");
