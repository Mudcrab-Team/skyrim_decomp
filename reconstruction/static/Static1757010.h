// Source exposure: binary-analysis; no external implementation source reused.
// Static1757010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757010*);
    virtual void release(Static1757010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757010*);
struct Static1757010 {
    void* value;
    Static1757010();
    ~Static1757010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
