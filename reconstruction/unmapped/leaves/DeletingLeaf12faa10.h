// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12faa10: GUESS(low) STANDIN
// DeletingLeaf12faa10Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12faa10Base
{
public:
    virtual ~DeletingLeaf12faa10Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12faa10 : public DeletingLeaf12faa10Base
{
public:
    explicit DeletingLeaf12faa10(void (*fn)());
    ~DeletingLeaf12faa10() override = default;  // compared: 0x12faa10 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12faa10) == 16, "size observed from the sized delete argument");
