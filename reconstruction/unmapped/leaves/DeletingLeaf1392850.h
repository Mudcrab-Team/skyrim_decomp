// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1392850: GUESS(low) STANDIN
// DeletingLeaf1392850Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1392850Base
{
public:
    virtual ~DeletingLeaf1392850Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1392850 : public DeletingLeaf1392850Base
{
public:
    explicit DeletingLeaf1392850(void (*fn)());
    ~DeletingLeaf1392850() override = default;  // compared: 0x1392850 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1392850) == 16, "size observed from the sized delete argument");
