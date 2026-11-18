// Source exposure: binary-analysis; no external implementation source reused.
// Static1771b90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771b90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771b90*);
    virtual void release(Static1771b90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771b90*);
struct Static1771b90 {
    void* value;
    Static1771b90();
    ~Static1771b90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
