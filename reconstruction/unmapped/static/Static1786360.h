// Source exposure: binary-analysis; no external implementation source reused.
// Static1786360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786360*);
    virtual void release(Static1786360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786360*);
struct Static1786360 {
    void* value;
    Static1786360();
    ~Static1786360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
