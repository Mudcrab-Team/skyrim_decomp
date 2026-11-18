// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac380*);
    virtual void release(Static17ac380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac380*);
struct Static17ac380 {
    void* value;
    Static17ac380();
    ~Static17ac380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
