// Source exposure: binary-analysis; no external implementation source reused.
// Static1757380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757380*);
    virtual void release(Static1757380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757380*);
struct Static1757380 {
    void* value;
    Static1757380();
    ~Static1757380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
