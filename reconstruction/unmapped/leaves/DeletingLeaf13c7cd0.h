// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13c7cd0: GUESS(low) STANDIN
// DeletingLeaf13c7cd0Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13c7cd0Base
{
public:
    virtual ~DeletingLeaf13c7cd0Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13c7cd0 : public DeletingLeaf13c7cd0Base
{
public:
    explicit DeletingLeaf13c7cd0(void (*fn)());
    ~DeletingLeaf13c7cd0() override = default;  // compared: 0x13c7cd0 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13c7cd0) == 16, "size observed from the sized delete argument");
