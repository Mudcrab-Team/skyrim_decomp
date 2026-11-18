// Source exposure: binary-analysis; no external implementation source reused.
// Static17ac830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ac830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ac830*);
    virtual void release(Static17ac830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ac830*);
struct Static17ac830 {
    void* value;
    Static17ac830();
    ~Static17ac830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
