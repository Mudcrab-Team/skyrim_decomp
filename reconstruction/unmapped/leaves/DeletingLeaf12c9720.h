// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf12c9720: GUESS(low) STANDIN
// DeletingLeaf12c9720Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf12c9720Base
{
public:
    virtual ~DeletingLeaf12c9720Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf12c9720 : public DeletingLeaf12c9720Base
{
public:
    explicit DeletingLeaf12c9720(void (*fn)());
    ~DeletingLeaf12c9720() override = default;  // compared: 0x12c9720 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf12c9720) == 16, "size observed from the sized delete argument");
