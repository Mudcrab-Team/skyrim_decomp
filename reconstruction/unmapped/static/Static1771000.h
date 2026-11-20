// Source exposure: binary-analysis; no external implementation source reused.
// Static1771000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771000*);
    virtual void release(Static1771000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771000*);
struct Static1771000 {
    void* value;
    Static1771000();
    ~Static1771000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
