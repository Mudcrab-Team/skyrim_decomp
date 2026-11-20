// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12adcd0: GUESS(low) STANDIN
// DeletingLeaf12adcd0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12adcd0Base
{
public:
    virtual ~DeletingLeaf12adcd0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12adcd0 : public DeletingLeaf12adcd0Base
{
public:
    explicit DeletingLeaf12adcd0(void (*fn)());
    ~DeletingLeaf12adcd0() override = default;  // compared: 0x12adcd0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12adcd0) == 16, "size observed from the sized delete argument");
