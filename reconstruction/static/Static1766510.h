// Source exposure: binary-analysis; no external implementation source reused.
// Static1766510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766510*);
    virtual void release(Static1766510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766510*);
struct Static1766510 {
    void* value;
    Static1766510();
    ~Static1766510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
