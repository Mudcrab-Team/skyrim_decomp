// Source exposure: binary-analysis; no external implementation source reused.
// Static17c4160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c4160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c4160*);
    virtual void release(Static17c4160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c4160*);
struct Static17c4160 {
    void* value;
    Static17c4160();
    ~Static17c4160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
