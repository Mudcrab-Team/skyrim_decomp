// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1337f00: GUESS(low) STANDIN
// DeletingLeaf1337f00Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1337f00Base
{
public:
    virtual ~DeletingLeaf1337f00Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1337f00 : public DeletingLeaf1337f00Base
{
public:
    explicit DeletingLeaf1337f00(void (*fn)());
    ~DeletingLeaf1337f00() override = default;  // compared: 0x1337f00 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1337f00) == 16, "size observed from the sized delete argument");
