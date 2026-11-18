// Source exposure: binary-analysis; no external implementation source reused.
// Static1769bc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769bc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769bc0*);
    virtual void release(Static1769bc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769bc0*);
struct Static1769bc0 {
    void* value;
    Static1769bc0();
    ~Static1769bc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
