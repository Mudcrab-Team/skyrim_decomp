// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1304300: GUESS(low) STANDIN
// DeletingLeaf1304300Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1304300Base
{
public:
    virtual ~DeletingLeaf1304300Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1304300 : public DeletingLeaf1304300Base
{
public:
    explicit DeletingLeaf1304300(void (*fn)());
    ~DeletingLeaf1304300() override = default;  // compared: 0x1304300 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1304300) == 16, "size observed from the sized delete argument");
