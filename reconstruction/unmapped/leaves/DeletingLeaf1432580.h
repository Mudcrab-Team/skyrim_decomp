// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1432580: GUESS(low) STANDIN
// DeletingLeaf1432580Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1432580Base
{
public:
    virtual ~DeletingLeaf1432580Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1432580 : public DeletingLeaf1432580Base
{
public:
    explicit DeletingLeaf1432580(void (*fn)());
    ~DeletingLeaf1432580() override = default;  // compared: 0x1432580 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1432580) == 16, "size observed from the sized delete argument");
