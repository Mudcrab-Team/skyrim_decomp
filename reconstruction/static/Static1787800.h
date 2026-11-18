// Source exposure: binary-analysis; no external implementation source reused.
// Static1787800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787800*);
    virtual void release(Static1787800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787800*);
struct Static1787800 {
    void* value;
    Static1787800();
    ~Static1787800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
