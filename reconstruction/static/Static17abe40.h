// Source exposure: binary-analysis; no external implementation source reused.
// Static17abe40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17abe40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17abe40*);
    virtual void release(Static17abe40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17abe40*);
struct Static17abe40 {
    void* value;
    Static17abe40();
    ~Static17abe40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
