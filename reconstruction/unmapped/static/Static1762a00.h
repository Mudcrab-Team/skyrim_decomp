// Source exposure: binary-analysis; no external implementation source reused.
// Static1762a00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762a00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762a00*);
    virtual void release(Static1762a00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762a00*);
struct Static1762a00 {
    void* value;
    Static1762a00();
    ~Static1762a00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
