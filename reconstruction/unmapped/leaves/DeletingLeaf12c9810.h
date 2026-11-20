// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12c9810: GUESS(low) STANDIN
// DeletingLeaf12c9810Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12c9810Base
{
public:
    virtual ~DeletingLeaf12c9810Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12c9810 : public DeletingLeaf12c9810Base
{
public:
    explicit DeletingLeaf12c9810(void (*fn)());
    ~DeletingLeaf12c9810() override = default;  // compared: 0x12c9810 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12c9810) == 16, "size observed from the sized delete argument");
