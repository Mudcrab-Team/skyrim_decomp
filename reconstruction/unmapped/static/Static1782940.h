// Source exposure: binary-analysis; no external implementation source reused.
// Static1782940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782940*);
    virtual void release(Static1782940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782940*);
struct Static1782940 {
    void* value;
    Static1782940();
    ~Static1782940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
