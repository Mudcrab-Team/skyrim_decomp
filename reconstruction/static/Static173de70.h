// Source exposure: binary-analysis; no external implementation source reused.
// Static173de70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173de70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173de70*);
    virtual void release(Static173de70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173de70*);
struct Static173de70 {
    void* value;
    Static173de70();
    ~Static173de70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
