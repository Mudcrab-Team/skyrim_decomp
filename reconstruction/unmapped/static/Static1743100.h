// Source exposure: binary-analysis; no external implementation source reused.
// Static1743100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743100*);
    virtual void release(Static1743100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743100*);
struct Static1743100 {
    void* value;
    Static1743100();
    ~Static1743100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
