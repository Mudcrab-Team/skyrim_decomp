// Source exposure: binary-analysis; no external implementation source reused.
// Static173cab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cab0*);
    virtual void release(Static173cab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cab0*);
struct Static173cab0 {
    void* value;
    Static173cab0();
    ~Static173cab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
