// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1432650: GUESS(low) STANDIN
// DeletingLeaf1432650Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1432650Base
{
public:
    virtual ~DeletingLeaf1432650Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1432650 : public DeletingLeaf1432650Base
{
public:
    explicit DeletingLeaf1432650(void (*fn)());
    ~DeletingLeaf1432650() override = default;  // compared: 0x1432650 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1432650) == 16, "size observed from the sized delete argument");
