// Source exposure: binary-analysis; no external implementation source reused.
// Static1757150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757150*);
    virtual void release(Static1757150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757150*);
struct Static1757150 {
    void* value;
    Static1757150();
    ~Static1757150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
