// Source exposure: binary-analysis; no external implementation source reused.
// Static17521a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17521a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17521a0*);
    virtual void release(Static17521a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17521a0*);
struct Static17521a0 {
    void* value;
    Static17521a0();
    ~Static17521a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
