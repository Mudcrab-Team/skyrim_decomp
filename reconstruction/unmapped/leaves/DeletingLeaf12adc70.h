// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12adc70: GUESS(low) STANDIN
// DeletingLeaf12adc70Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12adc70Base
{
public:
    virtual ~DeletingLeaf12adc70Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12adc70 : public DeletingLeaf12adc70Base
{
public:
    explicit DeletingLeaf12adc70(void (*fn)());
    ~DeletingLeaf12adc70() override = default;  // compared: 0x12adc70 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12adc70) == 16, "size observed from the sized delete argument");
