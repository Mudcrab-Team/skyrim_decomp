// Source exposure: binary-analysis; no external implementation source reused.
// Static1756750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756750*);
    virtual void release(Static1756750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756750*);
struct Static1756750 {
    void* value;
    Static1756750();
    ~Static1756750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
