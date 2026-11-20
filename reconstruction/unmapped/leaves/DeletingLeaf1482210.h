// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1482210: GUESS(low) STANDIN
// DeletingLeaf1482210Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1482210Base
{
public:
    virtual ~DeletingLeaf1482210Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1482210 : public DeletingLeaf1482210Base
{
public:
    explicit DeletingLeaf1482210(void (*fn)());
    ~DeletingLeaf1482210() override = default;  // compared: 0x1482210 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1482210) == 16, "size observed from the sized delete argument");
