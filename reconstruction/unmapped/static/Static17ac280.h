// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac280*);
    virtual void release(Static17ac280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac280*);
struct Static17ac280 {
    void* value;
    Static17ac280();
    ~Static17ac280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
