// Source exposure: binary-analysis; no external implementation source reused.
// Static1744010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744010*);
    virtual void release(Static1744010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744010*);
struct Static1744010 {
    void* value;
    Static1744010();
    ~Static1744010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
