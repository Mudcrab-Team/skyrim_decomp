// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac050*);
    virtual void release(Static17ac050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac050*);
struct Static17ac050 {
    void* value;
    Static17ac050();
    ~Static17ac050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
