// Source exposure: binary-analysis; no external implementation source reused.
// Static1795150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795150*);
    virtual void release(Static1795150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795150*);
struct Static1795150 {
    void* value;
    Static1795150();
    ~Static1795150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
