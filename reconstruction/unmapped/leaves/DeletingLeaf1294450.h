// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1294450: GUESS(low) STANDIN
// DeletingLeaf1294450Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1294450Base
{
public:
    virtual ~DeletingLeaf1294450Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1294450 : public DeletingLeaf1294450Base
{
public:
    explicit DeletingLeaf1294450(void (*fn)());
    ~DeletingLeaf1294450() override = default;  // compared: 0x1294450 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1294450) == 16, "size observed from the sized delete argument");
