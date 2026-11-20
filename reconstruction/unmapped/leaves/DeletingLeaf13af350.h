// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13af350: GUESS(low) STANDIN
// DeletingLeaf13af350Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13af350Base
{
public:
    virtual ~DeletingLeaf13af350Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13af350 : public DeletingLeaf13af350Base
{
public:
    explicit DeletingLeaf13af350(void (*fn)());
    ~DeletingLeaf13af350() override = default;  // compared: 0x13af350 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13af350) == 16, "size observed from the sized delete argument");
