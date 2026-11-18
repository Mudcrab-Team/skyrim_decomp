// Source exposure: binary-analysis; no external implementation source reused.
// Static1762640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762640*);
    virtual void release(Static1762640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762640*);
struct Static1762640 {
    void* value;
    Static1762640();
    ~Static1762640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
