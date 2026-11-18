// Source exposure: binary-analysis; no external implementation source reused.
// Static1765020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765020*);
    virtual void release(Static1765020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765020*);
struct Static1765020 {
    void* value;
    Static1765020();
    ~Static1765020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
