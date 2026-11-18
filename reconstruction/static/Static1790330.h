// Source exposure: binary-analysis; no external implementation source reused.
// Static1790330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790330*);
    virtual void release(Static1790330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790330*);
struct Static1790330 {
    void* value;
    Static1790330();
    ~Static1790330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
