// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1282a90: GUESS(low) STANDIN
// DeletingLeaf1282a90Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1282a90Base
{
public:
    virtual ~DeletingLeaf1282a90Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1282a90 : public DeletingLeaf1282a90Base
{
public:
    explicit DeletingLeaf1282a90(void (*fn)());
    ~DeletingLeaf1282a90() override = default;  // compared: 0x1282a90 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1282a90) == 16, "size observed from the sized delete argument");
