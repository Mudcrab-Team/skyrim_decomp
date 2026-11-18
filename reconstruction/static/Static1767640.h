// Source exposure: binary-analysis; no external implementation source reused.
// Static1767640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767640*);
    virtual void release(Static1767640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767640*);
struct Static1767640 {
    void* value;
    Static1767640();
    ~Static1767640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
