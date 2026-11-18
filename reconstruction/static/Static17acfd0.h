// Source exposure: binary-analysis; no external implementation source reused.
// Static17acfd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17acfd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17acfd0*);
    virtual void release(Static17acfd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17acfd0*);
struct Static17acfd0 {
    void* value;
    Static17acfd0();
    ~Static17acfd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
