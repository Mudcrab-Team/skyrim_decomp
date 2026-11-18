// Source exposure: binary-analysis; no external implementation source reused.
// Static17b5e20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b5e20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b5e20*);
    virtual void release(Static17b5e20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b5e20*);
struct Static17b5e20 {
    void* value;
    Static17b5e20();
    ~Static17b5e20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
