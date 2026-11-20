// Source exposure: binary-analysis; no external implementation source reused.
// Static17abe90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17abe90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17abe90*);
    virtual void release(Static17abe90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17abe90*);
struct Static17abe90 {
    void* value;
    Static17abe90();
    ~Static17abe90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
