// Source exposure: binary-analysis; no external implementation source reused.
// Static1765660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765660*);
    virtual void release(Static1765660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765660*);
struct Static1765660 {
    void* value;
    Static1765660();
    ~Static1765660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
