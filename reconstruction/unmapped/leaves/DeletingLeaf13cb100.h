// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf13cb100: GUESS(low) STANDIN
// DeletingLeaf13cb100Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf13cb100Base
{
public:
    virtual ~DeletingLeaf13cb100Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf13cb100 : public DeletingLeaf13cb100Base
{
public:
    explicit DeletingLeaf13cb100(void (*fn)());
    ~DeletingLeaf13cb100() override = default;  // compared: 0x13cb100 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf13cb100) == 16, "size observed from the sized delete argument");
