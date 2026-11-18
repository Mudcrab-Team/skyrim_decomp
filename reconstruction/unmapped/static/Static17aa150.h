// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa150*);
    virtual void release(Static17aa150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa150*);
struct Static17aa150 {
    void* value;
    Static17aa150();
    ~Static17aa150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
