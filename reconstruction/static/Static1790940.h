// Source exposure: binary-analysis; no external implementation source reused.
// Static1790940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790940*);
    virtual void release(Static1790940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790940*);
struct Static1790940 {
    void* value;
    Static1790940();
    ~Static1790940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
