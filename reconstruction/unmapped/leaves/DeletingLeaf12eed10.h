// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12eed10: GUESS(low) STANDIN
// DeletingLeaf12eed10Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12eed10Base
{
public:
    virtual ~DeletingLeaf12eed10Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12eed10 : public DeletingLeaf12eed10Base
{
public:
    explicit DeletingLeaf12eed10(void (*fn)());
    ~DeletingLeaf12eed10() override = default;  // compared: 0x12eed10 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12eed10) == 16, "size observed from the sized delete argument");
