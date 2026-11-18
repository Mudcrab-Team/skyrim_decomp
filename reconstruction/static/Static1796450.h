// Source exposure: binary-analysis; no external implementation source reused.
// Static1796450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796450*);
    virtual void release(Static1796450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796450*);
struct Static1796450 {
    void* value;
    Static1796450();
    ~Static1796450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
