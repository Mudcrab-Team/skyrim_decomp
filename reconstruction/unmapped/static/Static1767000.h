// Source exposure: binary-analysis; no external implementation source reused.
// Static1767000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767000*);
    virtual void release(Static1767000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767000*);
struct Static1767000 {
    void* value;
    Static1767000();
    ~Static1767000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
