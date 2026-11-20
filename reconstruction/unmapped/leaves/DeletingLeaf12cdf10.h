// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12cdf10: GUESS(low) STANDIN
// DeletingLeaf12cdf10Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12cdf10Base
{
public:
    virtual ~DeletingLeaf12cdf10Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12cdf10 : public DeletingLeaf12cdf10Base
{
public:
    explicit DeletingLeaf12cdf10(void (*fn)());
    ~DeletingLeaf12cdf10() override = default;  // compared: 0x12cdf10 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12cdf10) == 16, "size observed from the sized delete argument");
