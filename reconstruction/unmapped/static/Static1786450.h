// Source exposure: binary-analysis; no external implementation source reused.
// Static1786450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786450*);
    virtual void release(Static1786450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786450*);
struct Static1786450 {
    void* value;
    Static1786450();
    ~Static1786450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
