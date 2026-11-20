// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12d2250: GUESS(low) STANDIN
// DeletingLeaf12d2250Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12d2250Base
{
public:
    virtual ~DeletingLeaf12d2250Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12d2250 : public DeletingLeaf12d2250Base
{
public:
    explicit DeletingLeaf12d2250(void (*fn)());
    ~DeletingLeaf12d2250() override = default;  // compared: 0x12d2250 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12d2250) == 16, "size observed from the sized delete argument");
