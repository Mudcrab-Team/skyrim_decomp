// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1338730: GUESS(low) STANDIN
// DeletingLeaf1338730Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1338730Base
{
public:
    virtual ~DeletingLeaf1338730Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1338730 : public DeletingLeaf1338730Base
{
public:
    explicit DeletingLeaf1338730(void (*fn)());
    ~DeletingLeaf1338730() override = default;  // compared: 0x1338730 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1338730) == 16, "size observed from the sized delete argument");
