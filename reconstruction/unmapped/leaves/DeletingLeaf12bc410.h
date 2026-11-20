// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12bc410: GUESS(low) STANDIN
// DeletingLeaf12bc410Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12bc410Base
{
public:
    virtual ~DeletingLeaf12bc410Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12bc410 : public DeletingLeaf12bc410Base
{
public:
    explicit DeletingLeaf12bc410(void (*fn)());
    ~DeletingLeaf12bc410() override = default;  // compared: 0x12bc410 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12bc410) == 16, "size observed from the sized delete argument");
