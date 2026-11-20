// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1392930: GUESS(low) STANDIN
// DeletingLeaf1392930Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1392930Base
{
public:
    virtual ~DeletingLeaf1392930Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1392930 : public DeletingLeaf1392930Base
{
public:
    explicit DeletingLeaf1392930(void (*fn)());
    ~DeletingLeaf1392930() override = default;  // compared: 0x1392930 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1392930) == 16, "size observed from the sized delete argument");
