// Source exposure: binary-analysis; no external implementation source reused.
// Static1747480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747480*);
    virtual void release(Static1747480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747480*);
struct Static1747480 {
    void* value;
    Static1747480();
    ~Static1747480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
