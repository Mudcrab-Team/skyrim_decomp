// Source exposure: binary-analysis; no external implementation source reused.
// Static176c910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c910*);
    virtual void release(Static176c910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c910*);
struct Static176c910 {
    void* value;
    Static176c910();
    ~Static176c910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
