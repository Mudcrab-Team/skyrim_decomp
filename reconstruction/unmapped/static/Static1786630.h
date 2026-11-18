// Source exposure: binary-analysis; no external implementation source reused.
// Static1786630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786630*);
    virtual void release(Static1786630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786630*);
struct Static1786630 {
    void* value;
    Static1786630();
    ~Static1786630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
