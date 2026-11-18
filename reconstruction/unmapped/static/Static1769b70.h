// Source exposure: binary-analysis; no external implementation source reused.
// Static1769b70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769b70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769b70*);
    virtual void release(Static1769b70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769b70*);
struct Static1769b70 {
    void* value;
    Static1769b70();
    ~Static1769b70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
