// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13af320: GUESS(low) STANDIN
// DeletingLeaf13af320Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13af320Base
{
public:
    virtual ~DeletingLeaf13af320Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13af320 : public DeletingLeaf13af320Base
{
public:
    explicit DeletingLeaf13af320(void (*fn)());
    ~DeletingLeaf13af320() override = default;  // compared: 0x13af320 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13af320) == 16, "size observed from the sized delete argument");
