// Source exposure: binary-analysis; no external implementation source reused.
// Static1785640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785640*);
    virtual void release(Static1785640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785640*);
struct Static1785640 {
    void* value;
    Static1785640();
    ~Static1785640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
