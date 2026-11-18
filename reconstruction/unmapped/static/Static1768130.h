// Source exposure: binary-analysis; no external implementation source reused.
// Static1768130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768130*);
    virtual void release(Static1768130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768130*);
struct Static1768130 {
    void* value;
    Static1768130();
    ~Static1768130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
