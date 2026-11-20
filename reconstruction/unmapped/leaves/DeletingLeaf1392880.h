// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1392880: GUESS(low) STANDIN
// DeletingLeaf1392880Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1392880Base
{
public:
    virtual ~DeletingLeaf1392880Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1392880 : public DeletingLeaf1392880Base
{
public:
    explicit DeletingLeaf1392880(void (*fn)());
    ~DeletingLeaf1392880() override = default;  // compared: 0x1392880 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1392880) == 16, "size observed from the sized delete argument");
