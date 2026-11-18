// Source exposure: binary-analysis; no external implementation source reused.
// Static1752150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752150*);
    virtual void release(Static1752150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752150*);
struct Static1752150 {
    void* value;
    Static1752150();
    ~Static1752150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
