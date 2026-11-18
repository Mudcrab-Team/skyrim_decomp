// Source exposure: binary-analysis; no external implementation source reused.
// Static1753640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753640*);
    virtual void release(Static1753640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753640*);
struct Static1753640 {
    void* value;
    Static1753640();
    ~Static1753640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
