// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1259b60: GUESS(low) STANDIN
// DeletingLeaf1259b60Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1259b60Base
{
public:
    virtual ~DeletingLeaf1259b60Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1259b60 : public DeletingLeaf1259b60Base
{
public:
    explicit DeletingLeaf1259b60(void (*fn)());
    ~DeletingLeaf1259b60() override = default;  // compared: 0x1259b60 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1259b60) == 16, "size observed from the sized delete argument");
