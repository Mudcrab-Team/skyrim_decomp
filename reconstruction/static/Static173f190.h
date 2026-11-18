// Source exposure: binary-analysis; no external implementation source reused.
// Static173f190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f190*);
    virtual void release(Static173f190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f190*);
struct Static173f190 {
    void* value;
    Static173f190();
    ~Static173f190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
