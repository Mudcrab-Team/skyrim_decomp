// Source exposure: binary-analysis; no external implementation source reused.
// Static1786d60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786d60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786d60*);
    virtual void release(Static1786d60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786d60*);
struct Static1786d60 {
    void* value;
    Static1786d60();
    ~Static1786d60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
