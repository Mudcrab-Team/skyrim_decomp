// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12fa850: GUESS(low) STANDIN
// DeletingLeaf12fa850Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12fa850Base
{
public:
    virtual ~DeletingLeaf12fa850Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12fa850 : public DeletingLeaf12fa850Base
{
public:
    explicit DeletingLeaf12fa850(void (*fn)());
    ~DeletingLeaf12fa850() override = default;  // compared: 0x12fa850 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12fa850) == 16, "size observed from the sized delete argument");
