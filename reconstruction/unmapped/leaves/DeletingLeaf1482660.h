// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1482660: GUESS(low) STANDIN
// DeletingLeaf1482660Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1482660Base
{
public:
    virtual ~DeletingLeaf1482660Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1482660 : public DeletingLeaf1482660Base
{
public:
    explicit DeletingLeaf1482660(void (*fn)());
    ~DeletingLeaf1482660() override = default;  // compared: 0x1482660 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1482660) == 16, "size observed from the sized delete argument");
