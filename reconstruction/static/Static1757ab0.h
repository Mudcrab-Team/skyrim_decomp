// Source exposure: binary-analysis; no external implementation source reused.
// Static1757ab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757ab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757ab0*);
    virtual void release(Static1757ab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757ab0*);
struct Static1757ab0 {
    void* value;
    Static1757ab0();
    ~Static1757ab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
