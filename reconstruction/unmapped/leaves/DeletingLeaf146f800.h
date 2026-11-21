// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf146f800: GUESS(low) STANDIN
// DeletingLeaf146f800Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf146f800Base
{
public:
    virtual ~DeletingLeaf146f800Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf146f800 : public DeletingLeaf146f800Base
{
public:
    explicit DeletingLeaf146f800(void (*fn)());
    ~DeletingLeaf146f800() override = default;  // compared: 0x146f800 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf146f800) == 16, "size observed from the sized delete argument");
