// Source exposure: binary-analysis; no external implementation source reused.
// Static1771640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771640*);
    virtual void release(Static1771640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771640*);
struct Static1771640 {
    void* value;
    Static1771640();
    ~Static1771640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
