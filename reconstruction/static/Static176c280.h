// Source exposure: binary-analysis; no external implementation source reused.
// Static176c280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c280*);
    virtual void release(Static176c280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c280*);
struct Static176c280 {
    void* value;
    Static176c280();
    ~Static176c280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
