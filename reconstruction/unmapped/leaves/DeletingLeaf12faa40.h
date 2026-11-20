// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12faa40: GUESS(low) STANDIN
// DeletingLeaf12faa40Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12faa40Base
{
public:
    virtual ~DeletingLeaf12faa40Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12faa40 : public DeletingLeaf12faa40Base
{
public:
    explicit DeletingLeaf12faa40(void (*fn)());
    ~DeletingLeaf12faa40() override = default;  // compared: 0x12faa40 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12faa40) == 16, "size observed from the sized delete argument");
