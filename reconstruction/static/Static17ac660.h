// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac660*);
    virtual void release(Static17ac660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac660*);
struct Static17ac660 {
    void* value;
    Static17ac660();
    ~Static17ac660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
