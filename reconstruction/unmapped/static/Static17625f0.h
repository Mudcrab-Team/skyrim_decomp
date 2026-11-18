// Source exposure: binary-analysis; no external implementation source reused.
// Static17625f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17625f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17625f0*);
    virtual void release(Static17625f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17625f0*);
struct Static17625f0 {
    void* value;
    Static17625f0();
    ~Static17625f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
