// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf147c550: GUESS(low) STANDIN
// DeletingLeaf147c550Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf147c550Base
{
public:
    virtual ~DeletingLeaf147c550Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf147c550 : public DeletingLeaf147c550Base
{
public:
    explicit DeletingLeaf147c550(void (*fn)());
    ~DeletingLeaf147c550() override = default;  // compared: 0x147c550 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf147c550) == 16, "size observed from the sized delete argument");
