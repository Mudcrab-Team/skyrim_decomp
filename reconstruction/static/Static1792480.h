// Source exposure: binary-analysis; no external implementation source reused.
// Static1792480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792480*);
    virtual void release(Static1792480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792480*);
struct Static1792480 {
    void* value;
    Static1792480();
    ~Static1792480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
