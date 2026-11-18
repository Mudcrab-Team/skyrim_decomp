// Source exposure: binary-analysis; no external implementation source reused.
// Static1767fa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767fa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767fa0*);
    virtual void release(Static1767fa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767fa0*);
struct Static1767fa0 {
    void* value;
    Static1767fa0();
    ~Static1767fa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
