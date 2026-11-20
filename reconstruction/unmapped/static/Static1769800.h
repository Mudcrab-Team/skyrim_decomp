// Source exposure: binary-analysis; no external implementation source reused.
// Static1769800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769800*);
    virtual void release(Static1769800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769800*);
struct Static1769800 {
    void* value;
    Static1769800();
    ~Static1769800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
