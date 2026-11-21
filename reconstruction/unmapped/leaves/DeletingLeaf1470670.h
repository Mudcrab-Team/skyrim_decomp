// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1470670: GUESS(low) STANDIN
// DeletingLeaf1470670Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1470670Base
{
public:
    virtual ~DeletingLeaf1470670Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1470670 : public DeletingLeaf1470670Base
{
public:
    explicit DeletingLeaf1470670(void (*fn)());
    ~DeletingLeaf1470670() override = default;  // compared: 0x1470670 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1470670) == 16, "size observed from the sized delete argument");
