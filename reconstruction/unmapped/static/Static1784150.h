// Source exposure: binary-analysis; no external implementation source reused.
// Static1784150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784150*);
    virtual void release(Static1784150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784150*);
struct Static1784150 {
    void* value;
    Static1784150();
    ~Static1784150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
