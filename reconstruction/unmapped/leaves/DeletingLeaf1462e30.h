// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1462e30: GUESS(low) STANDIN
// DeletingLeaf1462e30Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1462e30Base
{
public:
    virtual ~DeletingLeaf1462e30Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1462e30 : public DeletingLeaf1462e30Base
{
public:
    explicit DeletingLeaf1462e30(void (*fn)());
    ~DeletingLeaf1462e30() override = default;  // compared: 0x1462e30 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1462e30) == 16, "size observed from the sized delete argument");
