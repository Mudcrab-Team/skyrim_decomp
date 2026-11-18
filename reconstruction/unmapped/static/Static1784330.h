// Source exposure: binary-analysis; no external implementation source reused.
// Static1784330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784330*);
    virtual void release(Static1784330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784330*);
struct Static1784330 {
    void* value;
    Static1784330();
    ~Static1784330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
