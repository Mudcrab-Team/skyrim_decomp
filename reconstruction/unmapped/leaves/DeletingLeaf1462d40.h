// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1462d40: GUESS(low) STANDIN
// DeletingLeaf1462d40Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1462d40Base
{
public:
    virtual ~DeletingLeaf1462d40Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1462d40 : public DeletingLeaf1462d40Base
{
public:
    explicit DeletingLeaf1462d40(void (*fn)());
    ~DeletingLeaf1462d40() override = default;  // compared: 0x1462d40 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1462d40) == 16, "size observed from the sized delete argument");
