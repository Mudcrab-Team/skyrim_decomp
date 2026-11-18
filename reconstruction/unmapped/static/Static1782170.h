// Source exposure: binary-analysis; no external implementation source reused.
// Static1782170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782170*);
    virtual void release(Static1782170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782170*);
struct Static1782170 {
    void* value;
    Static1782170();
    ~Static1782170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
