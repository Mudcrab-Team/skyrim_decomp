// Source exposure: binary-analysis; no external implementation source reused.
// Static17827b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17827b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17827b0*);
    virtual void release(Static17827b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17827b0*);
struct Static17827b0 {
    void* value;
    Static17827b0();
    ~Static17827b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
