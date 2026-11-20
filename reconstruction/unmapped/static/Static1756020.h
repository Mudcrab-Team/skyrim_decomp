// Source exposure: binary-analysis; no external implementation source reused.
// Static1756020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756020*);
    virtual void release(Static1756020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756020*);
struct Static1756020 {
    void* value;
    Static1756020();
    ~Static1756020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
