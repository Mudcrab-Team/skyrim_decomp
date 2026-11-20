// Source exposure: binary-analysis; no external implementation source reused.
// Static173fa20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173fa20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173fa20*);
    virtual void release(Static173fa20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173fa20*);
struct Static173fa20 {
    void* value;
    Static173fa20();
    ~Static173fa20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
