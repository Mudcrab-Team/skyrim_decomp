// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad660*);
    virtual void release(Static17ad660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad660*);
struct Static17ad660 {
    void* value;
    Static17ad660();
    ~Static17ad660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
