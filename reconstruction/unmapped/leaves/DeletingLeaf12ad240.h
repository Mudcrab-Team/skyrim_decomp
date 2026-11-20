// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12ad240: GUESS(low) STANDIN
// DeletingLeaf12ad240Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12ad240Base
{
public:
    virtual ~DeletingLeaf12ad240Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12ad240 : public DeletingLeaf12ad240Base
{
public:
    explicit DeletingLeaf12ad240(void (*fn)());
    ~DeletingLeaf12ad240() override = default;  // compared: 0x12ad240 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12ad240) == 16, "size observed from the sized delete argument");
