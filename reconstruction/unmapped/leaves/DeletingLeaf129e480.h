// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf129e480: GUESS(low) STANDIN
// DeletingLeaf129e480Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf129e480Base
{
public:
    virtual ~DeletingLeaf129e480Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf129e480 : public DeletingLeaf129e480Base
{
public:
    explicit DeletingLeaf129e480(void (*fn)());
    ~DeletingLeaf129e480() override = default;  // compared: 0x129e480 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf129e480) == 16, "size observed from the sized delete argument");
