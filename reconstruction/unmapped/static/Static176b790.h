// Source exposure: binary-analysis; no external implementation source reused.
// Static176b790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b790*);
    virtual void release(Static176b790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b790*);
struct Static176b790 {
    void* value;
    Static176b790();
    ~Static176b790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
