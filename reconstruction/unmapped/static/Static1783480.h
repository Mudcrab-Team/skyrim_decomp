// Source exposure: binary-analysis; no external implementation source reused.
// Static1783480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783480*);
    virtual void release(Static1783480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783480*);
struct Static1783480 {
    void* value;
    Static1783480();
    ~Static1783480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
