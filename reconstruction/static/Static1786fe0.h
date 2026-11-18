// Source exposure: binary-analysis; no external implementation source reused.
// Static1786fe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786fe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786fe0*);
    virtual void release(Static1786fe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786fe0*);
struct Static1786fe0 {
    void* value;
    Static1786fe0();
    ~Static1786fe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
