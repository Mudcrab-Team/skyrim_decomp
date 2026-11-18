// Source exposure: binary-analysis; no external implementation source reused.
// Static1748640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748640*);
    virtual void release(Static1748640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748640*);
struct Static1748640 {
    void* value;
    Static1748640();
    ~Static1748640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
