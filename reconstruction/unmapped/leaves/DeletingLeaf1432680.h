// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1432680: GUESS(low) STANDIN
// DeletingLeaf1432680Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1432680Base
{
public:
    virtual ~DeletingLeaf1432680Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1432680 : public DeletingLeaf1432680Base
{
public:
    explicit DeletingLeaf1432680(void (*fn)());
    ~DeletingLeaf1432680() override = default;  // compared: 0x1432680 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1432680) == 16, "size observed from the sized delete argument");
