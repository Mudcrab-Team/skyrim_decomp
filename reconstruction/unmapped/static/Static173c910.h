// Source exposure: binary-analysis; no external implementation source reused.
// Static173c910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c910*);
    virtual void release(Static173c910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c910*);
struct Static173c910 {
    void* value;
    Static173c910();
    ~Static173c910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
