// Source exposure: binary-analysis; no external implementation source reused.
// Static17acd80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17acd80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17acd80*);
    virtual void release(Static17acd80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17acd80*);
struct Static17acd80 {
    void* value;
    Static17acd80();
    ~Static17acd80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
