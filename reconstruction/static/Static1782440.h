// Source exposure: binary-analysis; no external implementation source reused.
// Static1782440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782440*);
    virtual void release(Static1782440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782440*);
struct Static1782440 {
    void* value;
    Static1782440();
    ~Static1782440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
