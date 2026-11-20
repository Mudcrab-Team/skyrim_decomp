// Source exposure: binary-analysis; no external implementation source reused.
// Static17609d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17609d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17609d0*);
    virtual void release(Static17609d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17609d0*);
struct Static17609d0 {
    void* value;
    Static17609d0();
    ~Static17609d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
