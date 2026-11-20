// Source exposure: binary-analysis; no external implementation source reused.
// Static1769760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769760*);
    virtual void release(Static1769760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769760*);
struct Static1769760 {
    void* value;
    Static1769760();
    ~Static1769760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
