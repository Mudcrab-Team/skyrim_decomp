// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac230*);
    virtual void release(Static17ac230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac230*);
struct Static17ac230 {
    void* value;
    Static17ac230();
    ~Static17ac230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
