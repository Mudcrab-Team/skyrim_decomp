// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf130a490: GUESS(low) STANDIN
// DeletingLeaf130a490Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf130a490Base
{
public:
    virtual ~DeletingLeaf130a490Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf130a490 : public DeletingLeaf130a490Base
{
public:
    explicit DeletingLeaf130a490(void (*fn)());
    ~DeletingLeaf130a490() override = default;  // compared: 0x130a490 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf130a490) == 16, "size observed from the sized delete argument");
