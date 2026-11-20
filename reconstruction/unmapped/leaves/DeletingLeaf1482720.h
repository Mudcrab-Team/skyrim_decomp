// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1482720: GUESS(low) STANDIN
// DeletingLeaf1482720Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1482720Base
{
public:
    virtual ~DeletingLeaf1482720Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1482720 : public DeletingLeaf1482720Base
{
public:
    explicit DeletingLeaf1482720(void (*fn)());
    ~DeletingLeaf1482720() override = default;  // compared: 0x1482720 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1482720) == 16, "size observed from the sized delete argument");
