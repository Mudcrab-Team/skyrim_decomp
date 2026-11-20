// Source exposure: binary-analysis; no external implementation source reused.
// Static177ae70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ae70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ae70*);
    virtual void release(Static177ae70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ae70*);
struct Static177ae70 {
    void* value;
    Static177ae70();
    ~Static177ae70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
