// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1283020: GUESS(low) STANDIN
// DeletingLeaf1283020Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1283020Base
{
public:
    virtual ~DeletingLeaf1283020Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1283020 : public DeletingLeaf1283020Base
{
public:
    explicit DeletingLeaf1283020(void (*fn)());
    ~DeletingLeaf1283020() override = default;  // compared: 0x1283020 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1283020) == 16, "size observed from the sized delete argument");
