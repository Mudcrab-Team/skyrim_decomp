// Source exposure: binary-analysis; no external implementation source reused.
// Static1795740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795740*);
    virtual void release(Static1795740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795740*);
struct Static1795740 {
    void* value;
    Static1795740();
    ~Static1795740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
