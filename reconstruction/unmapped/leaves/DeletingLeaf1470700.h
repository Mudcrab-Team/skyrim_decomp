// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1470700: GUESS(low) STANDIN
// DeletingLeaf1470700Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1470700Base
{
public:
    virtual ~DeletingLeaf1470700Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1470700 : public DeletingLeaf1470700Base
{
public:
    explicit DeletingLeaf1470700(void (*fn)());
    ~DeletingLeaf1470700() override = default;  // compared: 0x1470700 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1470700) == 16, "size observed from the sized delete argument");
