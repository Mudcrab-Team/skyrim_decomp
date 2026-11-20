// Source exposure: binary-analysis; no external implementation source reused.
// Static1757470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757470*);
    virtual void release(Static1757470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757470*);
struct Static1757470 {
    void* value;
    Static1757470();
    ~Static1757470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
