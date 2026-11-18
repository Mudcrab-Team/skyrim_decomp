// Source exposure: binary-analysis; no external implementation source reused.
// Static17b2300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b2300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b2300*);
    virtual void release(Static17b2300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b2300*);
struct Static17b2300 {
    void* value;
    Static17b2300();
    ~Static17b2300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
