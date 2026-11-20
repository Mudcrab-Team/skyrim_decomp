// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12eec80: GUESS(low) STANDIN
// DeletingLeaf12eec80Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12eec80Base
{
public:
    virtual ~DeletingLeaf12eec80Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12eec80 : public DeletingLeaf12eec80Base
{
public:
    explicit DeletingLeaf12eec80(void (*fn)());
    ~DeletingLeaf12eec80() override = default;  // compared: 0x12eec80 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12eec80) == 16, "size observed from the sized delete argument");
