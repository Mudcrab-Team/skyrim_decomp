// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12ebe80: GUESS(low) STANDIN
// DeletingLeaf12ebe80Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12ebe80Base
{
public:
    virtual ~DeletingLeaf12ebe80Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12ebe80 : public DeletingLeaf12ebe80Base
{
public:
    explicit DeletingLeaf12ebe80(void (*fn)());
    ~DeletingLeaf12ebe80() override = default;  // compared: 0x12ebe80 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12ebe80) == 16, "size observed from the sized delete argument");
