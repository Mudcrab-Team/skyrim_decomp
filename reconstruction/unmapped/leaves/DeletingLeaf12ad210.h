// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12ad210: GUESS(low) STANDIN
// DeletingLeaf12ad210Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12ad210Base
{
public:
    virtual ~DeletingLeaf12ad210Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12ad210 : public DeletingLeaf12ad210Base
{
public:
    explicit DeletingLeaf12ad210(void (*fn)());
    ~DeletingLeaf12ad210() override = default;  // compared: 0x12ad210 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12ad210) == 16, "size observed from the sized delete argument");
