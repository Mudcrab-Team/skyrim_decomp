// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa510*);
    virtual void release(Static17aa510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa510*);
struct Static17aa510 {
    void* value;
    Static17aa510();
    ~Static17aa510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
