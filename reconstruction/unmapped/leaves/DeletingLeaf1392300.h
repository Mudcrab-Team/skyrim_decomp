// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1392300: GUESS(low) STANDIN
// DeletingLeaf1392300Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1392300Base
{
public:
    virtual ~DeletingLeaf1392300Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1392300 : public DeletingLeaf1392300Base
{
public:
    explicit DeletingLeaf1392300(void (*fn)());
    ~DeletingLeaf1392300() override = default;  // compared: 0x1392300 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1392300) == 16, "size observed from the sized delete argument");
