// Source exposure: binary-analysis; no external implementation source reused.
// Static1755080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755080*);
    virtual void release(Static1755080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755080*);
struct Static1755080 {
    void* value;
    Static1755080();
    ~Static1755080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
