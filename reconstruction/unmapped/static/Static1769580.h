// Source exposure: binary-analysis; no external implementation source reused.
// Static1769580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769580*);
    virtual void release(Static1769580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769580*);
struct Static1769580 {
    void* value;
    Static1769580();
    ~Static1769580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
