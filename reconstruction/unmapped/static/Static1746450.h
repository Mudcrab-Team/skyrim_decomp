// Source exposure: binary-analysis; no external implementation source reused.
// Static1746450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746450*);
    virtual void release(Static1746450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746450*);
struct Static1746450 {
    void* value;
    Static1746450();
    ~Static1746450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
