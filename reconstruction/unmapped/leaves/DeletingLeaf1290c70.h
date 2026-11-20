// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1290c70: GUESS(low) STANDIN
// DeletingLeaf1290c70Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1290c70Base
{
public:
    virtual ~DeletingLeaf1290c70Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1290c70 : public DeletingLeaf1290c70Base
{
public:
    explicit DeletingLeaf1290c70(void (*fn)());
    ~DeletingLeaf1290c70() override = default;  // compared: 0x1290c70 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1290c70) == 16, "size observed from the sized delete argument");
