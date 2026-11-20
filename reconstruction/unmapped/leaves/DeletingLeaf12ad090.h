// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12ad090: GUESS(low) STANDIN
// DeletingLeaf12ad090Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12ad090Base
{
public:
    virtual ~DeletingLeaf12ad090Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12ad090 : public DeletingLeaf12ad090Base
{
public:
    explicit DeletingLeaf12ad090(void (*fn)());
    ~DeletingLeaf12ad090() override = default;  // compared: 0x12ad090 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12ad090) == 16, "size observed from the sized delete argument");
