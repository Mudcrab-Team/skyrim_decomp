// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad070*);
    virtual void release(Static17ad070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad070*);
struct Static17ad070 {
    void* value;
    Static17ad070();
    ~Static17ad070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
