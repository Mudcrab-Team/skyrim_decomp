// Source exposure: binary-analysis; no external implementation source reused.
// Static17b1c70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b1c70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b1c70*);
    virtual void release(Static17b1c70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b1c70*);
struct Static17b1c70 {
    void* value;
    Static17b1c70();
    ~Static17b1c70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
