// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac520*);
    virtual void release(Static17ac520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac520*);
struct Static17ac520 {
    void* value;
    Static17ac520();
    ~Static17ac520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
