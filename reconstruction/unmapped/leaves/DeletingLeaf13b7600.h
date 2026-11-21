// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13b7600: GUESS(low) STANDIN
// DeletingLeaf13b7600Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13b7600Base
{
public:
    virtual ~DeletingLeaf13b7600Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13b7600 : public DeletingLeaf13b7600Base
{
public:
    explicit DeletingLeaf13b7600(void (*fn)());
    ~DeletingLeaf13b7600() override = default;  // compared: 0x13b7600 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13b7600) == 16, "size observed from the sized delete argument");
