// Source exposure: binary-analysis; no external implementation source reused.
// Static17b0b70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b0b70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b0b70*);
    virtual void release(Static17b0b70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b0b70*);
struct Static17b0b70 {
    void* value;
    Static17b0b70();
    ~Static17b0b70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
