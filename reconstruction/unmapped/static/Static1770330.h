// Source exposure: binary-analysis; no external implementation source reused.
// Static1770330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770330*);
    virtual void release(Static1770330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770330*);
struct Static1770330 {
    void* value;
    Static1770330();
    ~Static1770330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
