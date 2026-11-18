// Source exposure: binary-analysis; no external implementation source reused.
// Static17c3f30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c3f30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c3f30*);
    virtual void release(Static17c3f30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c3f30*);
struct Static17c3f30 {
    void* value;
    Static17c3f30();
    ~Static17c3f30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
