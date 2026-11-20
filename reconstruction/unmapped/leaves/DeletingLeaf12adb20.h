// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12adb20: GUESS(low) STANDIN
// DeletingLeaf12adb20Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12adb20Base
{
public:
    virtual ~DeletingLeaf12adb20Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12adb20 : public DeletingLeaf12adb20Base
{
public:
    explicit DeletingLeaf12adb20(void (*fn)());
    ~DeletingLeaf12adb20() override = default;  // compared: 0x12adb20 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12adb20) == 16, "size observed from the sized delete argument");
