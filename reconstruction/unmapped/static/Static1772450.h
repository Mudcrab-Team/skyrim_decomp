// Source exposure: binary-analysis; no external implementation source reused.
// Static1772450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772450*);
    virtual void release(Static1772450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772450*);
struct Static1772450 {
    void* value;
    Static1772450();
    ~Static1772450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
