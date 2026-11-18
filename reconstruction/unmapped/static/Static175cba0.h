// Source exposure: binary-analysis; no external implementation source reused.
// Static175cba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cba0*);
    virtual void release(Static175cba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cba0*);
struct Static175cba0 {
    void* value;
    Static175cba0();
    ~Static175cba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
