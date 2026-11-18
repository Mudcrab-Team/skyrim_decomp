// Source exposure: binary-analysis; no external implementation source reused.
// Static17a7800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a7800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a7800*);
    virtual void release(Static17a7800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a7800*);
struct Static17a7800 {
    void* value;
    Static17a7800();
    ~Static17a7800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
