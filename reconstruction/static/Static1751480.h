// Source exposure: binary-analysis; no external implementation source reused.
// Static1751480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751480*);
    virtual void release(Static1751480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751480*);
struct Static1751480 {
    void* value;
    Static1751480();
    ~Static1751480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
