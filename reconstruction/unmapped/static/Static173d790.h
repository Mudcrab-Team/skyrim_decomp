// Source exposure: binary-analysis; no external implementation source reused.
// Static173d790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d790*);
    virtual void release(Static173d790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d790*);
struct Static173d790 {
    void* value;
    Static173d790();
    ~Static173d790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
