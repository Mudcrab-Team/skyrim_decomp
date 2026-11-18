// Source exposure: binary-analysis; no external implementation source reused.
// Static174bec0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bec0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bec0*);
    virtual void release(Static174bec0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bec0*);
struct Static174bec0 {
    void* value;
    Static174bec0();
    ~Static174bec0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
