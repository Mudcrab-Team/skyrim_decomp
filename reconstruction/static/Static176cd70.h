// Source exposure: binary-analysis; no external implementation source reused.
// Static176cd70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cd70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cd70*);
    virtual void release(Static176cd70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cd70*);
struct Static176cd70 {
    void* value;
    Static176cd70();
    ~Static176cd70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
