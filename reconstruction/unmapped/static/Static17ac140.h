// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac140*);
    virtual void release(Static17ac140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac140*);
struct Static17ac140 {
    void* value;
    Static17ac140();
    ~Static17ac140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
