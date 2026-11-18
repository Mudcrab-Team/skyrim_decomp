// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa470*);
    virtual void release(Static17aa470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa470*);
struct Static17aa470 {
    void* value;
    Static17aa470();
    ~Static17aa470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
