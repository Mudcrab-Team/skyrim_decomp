// Source exposure: binary-analysis; no external implementation source reused.
// Static1769df0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769df0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769df0*);
    virtual void release(Static1769df0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769df0*);
struct Static1769df0 {
    void* value;
    Static1769df0();
    ~Static1769df0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
