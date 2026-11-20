// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf129a430: GUESS(low) STANDIN
// DeletingLeaf129a430Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf129a430Base
{
public:
    virtual ~DeletingLeaf129a430Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf129a430 : public DeletingLeaf129a430Base
{
public:
    explicit DeletingLeaf129a430(void (*fn)());
    ~DeletingLeaf129a430() override = default;  // compared: 0x129a430 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf129a430) == 16, "size observed from the sized delete argument");
