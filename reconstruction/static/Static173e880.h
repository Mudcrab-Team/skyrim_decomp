// Source exposure: binary-analysis; no external implementation source reused.
// Static173e880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e880*);
    virtual void release(Static173e880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e880*);
struct Static173e880 {
    void* value;
    Static173e880();
    ~Static173e880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
