// Source exposure: binary-analysis; no external implementation source reused.
// Static177b960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b960*);
    virtual void release(Static177b960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b960*);
struct Static177b960 {
    void* value;
    Static177b960();
    ~Static177b960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
