// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12ad060: GUESS(low) STANDIN
// DeletingLeaf12ad060Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12ad060Base
{
public:
    virtual ~DeletingLeaf12ad060Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12ad060 : public DeletingLeaf12ad060Base
{
public:
    explicit DeletingLeaf12ad060(void (*fn)());
    ~DeletingLeaf12ad060() override = default;  // compared: 0x12ad060 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12ad060) == 16, "size observed from the sized delete argument");
