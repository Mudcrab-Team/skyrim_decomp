// Source exposure: binary-analysis; no external implementation source reused.
// Static1769080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769080*);
    virtual void release(Static1769080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769080*);
struct Static1769080 {
    void* value;
    Static1769080();
    ~Static1769080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
