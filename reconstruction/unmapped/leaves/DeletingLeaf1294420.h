// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1294420: GUESS(low) STANDIN
// DeletingLeaf1294420Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1294420Base
{
public:
    virtual ~DeletingLeaf1294420Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1294420 : public DeletingLeaf1294420Base
{
public:
    explicit DeletingLeaf1294420(void (*fn)());
    ~DeletingLeaf1294420() override = default;  // compared: 0x1294420 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1294420) == 16, "size observed from the sized delete argument");
