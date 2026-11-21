// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1482360: GUESS(low) STANDIN
// DeletingLeaf1482360Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1482360Base
{
public:
    virtual ~DeletingLeaf1482360Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1482360 : public DeletingLeaf1482360Base
{
public:
    explicit DeletingLeaf1482360(void (*fn)());
    ~DeletingLeaf1482360() override = default;  // compared: 0x1482360 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1482360) == 16, "size observed from the sized delete argument");
