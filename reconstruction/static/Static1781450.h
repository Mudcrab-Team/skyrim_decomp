// Source exposure: binary-analysis; no external implementation source reused.
// Static1781450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781450*);
    virtual void release(Static1781450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781450*);
struct Static1781450 {
    void* value;
    Static1781450();
    ~Static1781450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
