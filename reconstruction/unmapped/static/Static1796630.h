// Source exposure: binary-analysis; no external implementation source reused.
// Static1796630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796630*);
    virtual void release(Static1796630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796630*);
struct Static1796630 {
    void* value;
    Static1796630();
    ~Static1796630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
