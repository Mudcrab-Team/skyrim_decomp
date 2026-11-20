// Source exposure: binary-analysis; no external implementation source reused.
// Static17b4330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b4330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b4330*);
    virtual void release(Static17b4330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b4330*);
struct Static17b4330 {
    void* value;
    Static17b4330();
    ~Static17b4330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
