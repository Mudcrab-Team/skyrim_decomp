// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1283190: GUESS(low) STANDIN
// DeletingLeaf1283190Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1283190Base
{
public:
    virtual ~DeletingLeaf1283190Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1283190 : public DeletingLeaf1283190Base
{
public:
    explicit DeletingLeaf1283190(void (*fn)());
    ~DeletingLeaf1283190() override = default;  // compared: 0x1283190 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1283190) == 16, "size observed from the sized delete argument");
