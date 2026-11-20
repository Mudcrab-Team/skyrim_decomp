// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf129e420: GUESS(low) STANDIN
// DeletingLeaf129e420Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf129e420Base
{
public:
    virtual ~DeletingLeaf129e420Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf129e420 : public DeletingLeaf129e420Base
{
public:
    explicit DeletingLeaf129e420(void (*fn)());
    ~DeletingLeaf129e420() override = default;  // compared: 0x129e420 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf129e420) == 16, "size observed from the sized delete argument");
