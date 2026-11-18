// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad340*);
    virtual void release(Static17ad340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad340*);
struct Static17ad340 {
    void* value;
    Static17ad340();
    ~Static17ad340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
