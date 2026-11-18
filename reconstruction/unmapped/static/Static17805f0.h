// Source exposure: binary-analysis; no external implementation source reused.
// Static17805f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17805f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17805f0*);
    virtual void release(Static17805f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17805f0*);
struct Static17805f0 {
    void* value;
    Static17805f0();
    ~Static17805f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
