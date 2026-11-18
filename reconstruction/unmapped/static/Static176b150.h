// Source exposure: binary-analysis; no external implementation source reused.
// Static176b150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b150*);
    virtual void release(Static176b150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b150*);
struct Static176b150 {
    void* value;
    Static176b150();
    ~Static176b150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
