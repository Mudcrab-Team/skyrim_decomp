// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf130db00: GUESS(low) STANDIN
// DeletingLeaf130db00Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf130db00Base
{
public:
    virtual ~DeletingLeaf130db00Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf130db00 : public DeletingLeaf130db00Base
{
public:
    explicit DeletingLeaf130db00(void (*fn)());
    ~DeletingLeaf130db00() override = default;  // compared: 0x130db00 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf130db00) == 16, "size observed from the sized delete argument");
