// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1462e00: GUESS(low) STANDIN
// DeletingLeaf1462e00Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1462e00Base
{
public:
    virtual ~DeletingLeaf1462e00Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1462e00 : public DeletingLeaf1462e00Base
{
public:
    explicit DeletingLeaf1462e00(void (*fn)());
    ~DeletingLeaf1462e00() override = default;  // compared: 0x1462e00 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1462e00) == 16, "size observed from the sized delete argument");
