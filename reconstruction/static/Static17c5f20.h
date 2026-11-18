// Source exposure: binary-analysis; no external implementation source reused.
// Static17c5f20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c5f20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c5f20*);
    virtual void release(Static17c5f20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c5f20*);
struct Static17c5f20 {
    void* value;
    Static17c5f20();
    ~Static17c5f20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
