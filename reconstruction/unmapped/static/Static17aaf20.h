// Source exposure: binary-analysis; no external implementation source reused.
// Static17aaf20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aaf20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aaf20*);
    virtual void release(Static17aaf20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aaf20*);
struct Static17aaf20 {
    void* value;
    Static17aaf20();
    ~Static17aaf20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
