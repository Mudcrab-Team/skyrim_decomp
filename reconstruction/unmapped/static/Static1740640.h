// Source exposure: binary-analysis; no external implementation source reused.
// Static1740640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740640*);
    virtual void release(Static1740640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740640*);
struct Static1740640 {
    void* value;
    Static1740640();
    ~Static1740640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
