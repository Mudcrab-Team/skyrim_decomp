// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac330*);
    virtual void release(Static17ac330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac330*);
struct Static17ac330 {
    void* value;
    Static17ac330();
    ~Static17ac330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
