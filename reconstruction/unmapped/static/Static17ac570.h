// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac570*);
    virtual void release(Static17ac570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac570*);
struct Static17ac570 {
    void* value;
    Static17ac570();
    ~Static17ac570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
