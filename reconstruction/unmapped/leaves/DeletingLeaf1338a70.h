// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1338a70: GUESS(low) STANDIN
// DeletingLeaf1338a70Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1338a70Base
{
public:
    virtual ~DeletingLeaf1338a70Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1338a70 : public DeletingLeaf1338a70Base
{
public:
    explicit DeletingLeaf1338a70(void (*fn)());
    ~DeletingLeaf1338a70() override = default;  // compared: 0x1338a70 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1338a70) == 16, "size observed from the sized delete argument");
