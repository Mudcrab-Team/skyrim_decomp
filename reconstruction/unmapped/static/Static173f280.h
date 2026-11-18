// Source exposure: binary-analysis; no external implementation source reused.
// Static173f280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f280*);
    virtual void release(Static173f280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f280*);
struct Static173f280 {
    void* value;
    Static173f280();
    ~Static173f280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
