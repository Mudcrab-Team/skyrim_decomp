// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf130db30: GUESS(low) STANDIN
// DeletingLeaf130db30Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf130db30Base
{
public:
    virtual ~DeletingLeaf130db30Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf130db30 : public DeletingLeaf130db30Base
{
public:
    explicit DeletingLeaf130db30(void (*fn)());
    ~DeletingLeaf130db30() override = default;  // compared: 0x130db30 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf130db30) == 16, "size observed from the sized delete argument");
