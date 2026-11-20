// Source exposure: binary-analysis; no external implementation source reused.
// Static17511b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17511b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17511b0*);
    virtual void release(Static17511b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17511b0*);
struct Static17511b0 {
    void* value;
    Static17511b0();
    ~Static17511b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
