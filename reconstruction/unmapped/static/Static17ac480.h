// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac480*);
    virtual void release(Static17ac480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac480*);
struct Static17ac480 {
    void* value;
    Static17ac480();
    ~Static17ac480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
