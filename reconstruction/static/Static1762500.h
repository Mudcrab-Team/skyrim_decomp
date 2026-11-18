// Source exposure: binary-analysis; no external implementation source reused.
// Static1762500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762500*);
    virtual void release(Static1762500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762500*);
struct Static1762500 {
    void* value;
    Static1762500();
    ~Static1762500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
