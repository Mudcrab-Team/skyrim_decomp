// Source exposure: binary-analysis; no external implementation source reused.
// Static17472f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17472f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17472f0*);
    virtual void release(Static17472f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17472f0*);
struct Static17472f0 {
    void* value;
    Static17472f0();
    ~Static17472f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
