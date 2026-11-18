// Source exposure: binary-analysis; no external implementation source reused.
// Static17add40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17add40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17add40*);
    virtual void release(Static17add40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17add40*);
struct Static17add40 {
    void* value;
    Static17add40();
    ~Static17add40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
