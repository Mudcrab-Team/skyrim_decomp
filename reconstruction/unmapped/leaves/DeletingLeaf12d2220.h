// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12d2220: GUESS(low) STANDIN
// DeletingLeaf12d2220Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12d2220Base
{
public:
    virtual ~DeletingLeaf12d2220Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12d2220 : public DeletingLeaf12d2220Base
{
public:
    explicit DeletingLeaf12d2220(void (*fn)());
    ~DeletingLeaf12d2220() override = default;  // compared: 0x12d2220 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12d2220) == 16, "size observed from the sized delete argument");
