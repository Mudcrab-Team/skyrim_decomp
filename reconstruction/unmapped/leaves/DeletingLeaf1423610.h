// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1423610: GUESS(low) STANDIN
// DeletingLeaf1423610Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1423610Base
{
public:
    virtual ~DeletingLeaf1423610Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1423610 : public DeletingLeaf1423610Base
{
public:
    explicit DeletingLeaf1423610(void (*fn)());
    ~DeletingLeaf1423610() override = default;  // compared: 0x1423610 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1423610) == 16, "size observed from the sized delete argument");
