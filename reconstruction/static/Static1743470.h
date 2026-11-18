// Source exposure: binary-analysis; no external implementation source reused.
// Static1743470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743470*);
    virtual void release(Static1743470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743470*);
struct Static1743470 {
    void* value;
    Static1743470();
    ~Static1743470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
