// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1462b20: GUESS(low) STANDIN
// DeletingLeaf1462b20Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1462b20Base
{
public:
    virtual ~DeletingLeaf1462b20Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1462b20 : public DeletingLeaf1462b20Base
{
public:
    explicit DeletingLeaf1462b20(void (*fn)());
    ~DeletingLeaf1462b20() override = default;  // compared: 0x1462b20 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1462b20) == 16, "size observed from the sized delete argument");
