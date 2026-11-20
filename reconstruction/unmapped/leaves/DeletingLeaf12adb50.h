// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12adb50: GUESS(low) STANDIN
// DeletingLeaf12adb50Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12adb50Base
{
public:
    virtual ~DeletingLeaf12adb50Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12adb50 : public DeletingLeaf12adb50Base
{
public:
    explicit DeletingLeaf12adb50(void (*fn)());
    ~DeletingLeaf12adb50() override = default;  // compared: 0x12adb50 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12adb50) == 16, "size observed from the sized delete argument");
