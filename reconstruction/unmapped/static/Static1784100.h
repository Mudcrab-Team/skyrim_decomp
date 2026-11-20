// Source exposure: binary-analysis; no external implementation source reused.
// Static1784100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784100*);
    virtual void release(Static1784100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784100*);
struct Static1784100 {
    void* value;
    Static1784100();
    ~Static1784100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
