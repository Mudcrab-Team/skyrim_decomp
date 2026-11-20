// Source exposure: binary-analysis; no external implementation source reused.
// Static1763130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763130*);
    virtual void release(Static1763130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763130*);
struct Static1763130 {
    void* value;
    Static1763130();
    ~Static1763130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
