// Source exposure: binary-analysis; no external implementation source reused.
// Static1767500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767500*);
    virtual void release(Static1767500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767500*);
struct Static1767500 {
    void* value;
    Static1767500();
    ~Static1767500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
