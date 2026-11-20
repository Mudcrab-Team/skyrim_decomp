// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12bc170: GUESS(low) STANDIN
// DeletingLeaf12bc170Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12bc170Base
{
public:
    virtual ~DeletingLeaf12bc170Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12bc170 : public DeletingLeaf12bc170Base
{
public:
    explicit DeletingLeaf12bc170(void (*fn)());
    ~DeletingLeaf12bc170() override = default;  // compared: 0x12bc170 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12bc170) == 16, "size observed from the sized delete argument");
