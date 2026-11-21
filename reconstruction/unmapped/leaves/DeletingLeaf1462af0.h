// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1462af0: GUESS(low) STANDIN
// DeletingLeaf1462af0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1462af0Base
{
public:
    virtual ~DeletingLeaf1462af0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1462af0 : public DeletingLeaf1462af0Base
{
public:
    explicit DeletingLeaf1462af0(void (*fn)());
    ~DeletingLeaf1462af0() override = default;  // compared: 0x1462af0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1462af0) == 16, "size observed from the sized delete argument");
