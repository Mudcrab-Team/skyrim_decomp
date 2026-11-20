// Source exposure: binary-analysis; no external implementation source reused.
// Static173d880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d880*);
    virtual void release(Static173d880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d880*);
struct Static173d880 {
    void* value;
    Static173d880();
    ~Static173d880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
