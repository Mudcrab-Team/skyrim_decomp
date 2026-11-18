// Source exposure: binary-analysis; no external implementation source reused.
// Static17895d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17895d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17895d0*);
    virtual void release(Static17895d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17895d0*);
struct Static17895d0 {
    void* value;
    Static17895d0();
    ~Static17895d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
