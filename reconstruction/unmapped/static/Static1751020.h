// Source exposure: binary-analysis; no external implementation source reused.
// Static1751020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751020*);
    virtual void release(Static1751020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751020*);
struct Static1751020 {
    void* value;
    Static1751020();
    ~Static1751020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
