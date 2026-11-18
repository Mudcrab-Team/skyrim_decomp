// Source exposure: binary-analysis; no external implementation source reused.
// Static1775150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775150*);
    virtual void release(Static1775150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775150*);
struct Static1775150 {
    void* value;
    Static1775150();
    ~Static1775150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
