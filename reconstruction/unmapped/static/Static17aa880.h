// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa880*);
    virtual void release(Static17aa880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa880*);
struct Static17aa880 {
    void* value;
    Static17aa880();
    ~Static17aa880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
