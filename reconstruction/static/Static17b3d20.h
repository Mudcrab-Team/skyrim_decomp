// Source exposure: binary-analysis; no external implementation source reused.
// Static17b3d20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b3d20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b3d20*);
    virtual void release(Static17b3d20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b3d20*);
struct Static17b3d20 {
    void* value;
    Static17b3d20();
    ~Static17b3d20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
