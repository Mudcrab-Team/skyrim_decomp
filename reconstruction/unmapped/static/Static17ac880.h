// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac880*);
    virtual void release(Static17ac880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac880*);
struct Static17ac880 {
    void* value;
    Static17ac880();
    ~Static17ac880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
