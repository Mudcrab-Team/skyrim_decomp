// Source exposure: binary-analysis; no external implementation source reused.
// Static17808c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17808c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17808c0*);
    virtual void release(Static17808c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17808c0*);
struct Static17808c0 {
    void* value;
    Static17808c0();
    ~Static17808c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
