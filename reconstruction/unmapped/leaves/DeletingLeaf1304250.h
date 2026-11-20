// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1304250: GUESS(low) STANDIN
// DeletingLeaf1304250Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1304250Base
{
public:
    virtual ~DeletingLeaf1304250Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1304250 : public DeletingLeaf1304250Base
{
public:
    explicit DeletingLeaf1304250(void (*fn)());
    ~DeletingLeaf1304250() override = default;  // compared: 0x1304250 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1304250) == 16, "size observed from the sized delete argument");
