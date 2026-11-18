// Source exposure: binary-analysis; no external implementation source reused.
// Static175cec0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cec0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cec0*);
    virtual void release(Static175cec0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cec0*);
struct Static175cec0 {
    void* value;
    Static175cec0();
    ~Static175cec0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
