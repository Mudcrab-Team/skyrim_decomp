// Source exposure: binary-analysis; no external implementation source reused.
// Static177a150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a150*);
    virtual void release(Static177a150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a150*);
struct Static177a150 {
    void* value;
    Static177a150();
    ~Static177a150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
