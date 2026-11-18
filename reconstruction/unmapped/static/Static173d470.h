// Source exposure: binary-analysis; no external implementation source reused.
// Static173d470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d470*);
    virtual void release(Static173d470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d470*);
struct Static173d470 {
    void* value;
    Static173d470();
    ~Static173d470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
