// Source exposure: binary-analysis; no external implementation source reused.
// Static17615b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17615b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17615b0*);
    virtual void release(Static17615b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17615b0*);
struct Static17615b0 {
    void* value;
    Static17615b0();
    ~Static17615b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
