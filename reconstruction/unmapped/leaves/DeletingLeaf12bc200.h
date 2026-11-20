// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12bc200: GUESS(low) STANDIN
// DeletingLeaf12bc200Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12bc200Base
{
public:
    virtual ~DeletingLeaf12bc200Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12bc200 : public DeletingLeaf12bc200Base
{
public:
    explicit DeletingLeaf12bc200(void (*fn)());
    ~DeletingLeaf12bc200() override = default;  // compared: 0x12bc200 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12bc200) == 16, "size observed from the sized delete argument");
