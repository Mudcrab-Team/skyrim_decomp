// Source exposure: binary-analysis; no external implementation source reused.
// Static1766150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766150*);
    virtual void release(Static1766150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766150*);
struct Static1766150 {
    void* value;
    Static1766150();
    ~Static1766150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
