// Source exposure: binary-analysis; no external implementation source reused.
// Static1768900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768900*);
    virtual void release(Static1768900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768900*);
struct Static1768900 {
    void* value;
    Static1768900();
    ~Static1768900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
