// Source exposure: binary-analysis; no external implementation source reused.
// Static1757600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757600*);
    virtual void release(Static1757600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757600*);
struct Static1757600 {
    void* value;
    Static1757600();
    ~Static1757600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
