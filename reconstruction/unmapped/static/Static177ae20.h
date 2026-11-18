// Source exposure: binary-analysis; no external implementation source reused.
// Static177ae20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ae20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ae20*);
    virtual void release(Static177ae20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ae20*);
struct Static177ae20 {
    void* value;
    Static177ae20();
    ~Static177ae20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
