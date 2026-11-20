// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1259aa0 (reconstruction/skyrim/papyrus/LogFunctionCallableLayout.cpp); no external declaration or body reused.
// DeletingLeaf1432520: GUESS(low) STANDIN
// DeletingLeaf1432520Base, callback: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1432520Base
{
public:
    virtual ~DeletingLeaf1432520Base() = default;
    virtual void Invoke() = 0;
};

class DeletingLeaf1432520 : public DeletingLeaf1432520Base
{
public:
    explicit DeletingLeaf1432520(void (*fn)());
    ~DeletingLeaf1432520() override = default;  // compared: 0x1432520 (scalar deleting destructor)
    void Invoke() override;
    void (*callback)();
};
static_assert(sizeof(DeletingLeaf1432520) == 16, "size observed from the sized delete argument");
