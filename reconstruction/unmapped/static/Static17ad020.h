// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad020*);
    virtual void release(Static17ad020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad020*);
struct Static17ad020 {
    void* value;
    Static17ad020();
    ~Static17ad020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
