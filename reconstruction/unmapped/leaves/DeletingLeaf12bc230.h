// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12bc230: GUESS(low) STANDIN
// DeletingLeaf12bc230Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12bc230Base
{
public:
    virtual ~DeletingLeaf12bc230Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12bc230 : public DeletingLeaf12bc230Base
{
public:
    explicit DeletingLeaf12bc230(void (*fn)());
    ~DeletingLeaf12bc230() override = default;  // compared: 0x12bc230 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12bc230) == 16, "size observed from the sized delete argument");
