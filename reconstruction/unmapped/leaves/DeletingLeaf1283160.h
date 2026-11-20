// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1283160: GUESS(low) STANDIN
// DeletingLeaf1283160Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1283160Base
{
public:
    virtual ~DeletingLeaf1283160Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1283160 : public DeletingLeaf1283160Base
{
public:
    explicit DeletingLeaf1283160(void (*fn)());
    ~DeletingLeaf1283160() override = default;  // compared: 0x1283160 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1283160) == 16, "size observed from the sized delete argument");
