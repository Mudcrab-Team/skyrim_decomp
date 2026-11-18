// Source exposure: binary-analysis; no external implementation source reused.
// Static1777450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777450*);
    virtual void release(Static1777450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777450*);
struct Static1777450 {
    void* value;
    Static1777450();
    ~Static1777450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
