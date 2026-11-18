// Source exposure: binary-analysis; no external implementation source reused.
// Static176d810, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d810;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d810*);
    virtual void release(Static176d810*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d810*);
struct Static176d810 {
    void* value;
    Static176d810();
    ~Static176d810() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
