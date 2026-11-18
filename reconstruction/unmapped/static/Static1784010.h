// Source exposure: binary-analysis; no external implementation source reused.
// Static1784010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784010*);
    virtual void release(Static1784010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784010*);
struct Static1784010 {
    void* value;
    Static1784010();
    ~Static1784010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
