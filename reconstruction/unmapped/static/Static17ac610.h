// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac610*);
    virtual void release(Static17ac610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac610*);
struct Static17ac610 {
    void* value;
    Static17ac610();
    ~Static17ac610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
