// Source exposure: binary-analysis; no external implementation source reused.
// Static1744150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744150*);
    virtual void release(Static1744150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744150*);
struct Static1744150 {
    void* value;
    Static1744150();
    ~Static1744150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
