// Source exposure: binary-analysis; no external implementation source reused.
// Static1746940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746940*);
    virtual void release(Static1746940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746940*);
struct Static1746940 {
    void* value;
    Static1746940();
    ~Static1746940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
