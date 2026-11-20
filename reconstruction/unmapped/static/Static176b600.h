// Source exposure: binary-analysis; no external implementation source reused.
// Static176b600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b600*);
    virtual void release(Static176b600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b600*);
struct Static176b600 {
    void* value;
    Static176b600();
    ~Static176b600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
