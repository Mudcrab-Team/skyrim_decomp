// Source exposure: binary-analysis; no external implementation source reused.
// Static1744470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744470*);
    virtual void release(Static1744470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744470*);
struct Static1744470 {
    void* value;
    Static1744470();
    ~Static1744470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
