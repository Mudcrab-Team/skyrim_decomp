// Source exposure: binary-analysis; no external implementation source reused.
// Static1740450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740450*);
    virtual void release(Static1740450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740450*);
struct Static1740450 {
    void* value;
    Static1740450();
    ~Static1740450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
