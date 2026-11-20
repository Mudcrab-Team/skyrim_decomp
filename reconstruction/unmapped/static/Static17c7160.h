// Source exposure: binary-analysis; no external implementation source reused.
// Static17c7160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c7160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c7160*);
    virtual void release(Static17c7160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c7160*);
struct Static17c7160 {
    void* value;
    Static17c7160();
    ~Static17c7160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
