// Source exposure: binary-analysis; no external implementation source reused.
// Static1762190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762190*);
    virtual void release(Static1762190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762190*);
struct Static1762190 {
    void* value;
    Static1762190();
    ~Static1762190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
