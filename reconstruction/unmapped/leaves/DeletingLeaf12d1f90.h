// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12d1f90: GUESS(low) STANDIN
// DeletingLeaf12d1f90Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12d1f90Base
{
public:
    virtual ~DeletingLeaf12d1f90Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12d1f90 : public DeletingLeaf12d1f90Base
{
public:
    explicit DeletingLeaf12d1f90(void (*fn)());
    ~DeletingLeaf12d1f90() override = default;  // compared: 0x12d1f90 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12d1f90) == 16, "size observed from the sized delete argument");
