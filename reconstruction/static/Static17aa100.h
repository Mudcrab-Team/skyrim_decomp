// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa100*);
    virtual void release(Static17aa100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa100*);
struct Static17aa100 {
    void* value;
    Static17aa100();
    ~Static17aa100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
