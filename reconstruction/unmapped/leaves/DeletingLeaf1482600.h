// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1482600: GUESS(low) STANDIN
// DeletingLeaf1482600Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1482600Base
{
public:
    virtual ~DeletingLeaf1482600Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1482600 : public DeletingLeaf1482600Base
{
public:
    explicit DeletingLeaf1482600(void (*fn)());
    ~DeletingLeaf1482600() override = default;  // compared: 0x1482600 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1482600) == 16, "size observed from the sized delete argument");
