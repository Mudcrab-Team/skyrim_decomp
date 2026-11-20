// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13c8780: GUESS(low) STANDIN
// DeletingLeaf13c8780Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13c8780Base
{
public:
    virtual ~DeletingLeaf13c8780Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13c8780 : public DeletingLeaf13c8780Base
{
public:
    explicit DeletingLeaf13c8780(void (*fn)());
    ~DeletingLeaf13c8780() override = default;  // compared: 0x13c8780 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13c8780) == 16, "size observed from the sized delete argument");
