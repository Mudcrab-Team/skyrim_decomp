// Source exposure: binary-analysis; no external implementation source reused.
// Static1797470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1797470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1797470*);
    virtual void release(Static1797470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1797470*);
struct Static1797470 {
    void* value;
    Static1797470();
    ~Static1797470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
