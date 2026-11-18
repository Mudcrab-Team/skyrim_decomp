// Source exposure: binary-analysis; no external implementation source reused.
// Static17ace30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ace30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ace30*);
    virtual void release(Static17ace30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ace30*);
struct Static17ace30 {
    void* value;
    Static17ace30();
    ~Static17ace30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
