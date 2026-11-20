// Source exposure: binary-analysis; no external implementation source reused.
// Static1790480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790480*);
    virtual void release(Static1790480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790480*);
struct Static1790480 {
    void* value;
    Static1790480();
    ~Static1790480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
