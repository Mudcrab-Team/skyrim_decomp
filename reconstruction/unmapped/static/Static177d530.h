// Source exposure: binary-analysis; no external implementation source reused.
// Static177d530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d530*);
    virtual void release(Static177d530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d530*);
struct Static177d530 {
    void* value;
    Static177d530();
    ~Static177d530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
