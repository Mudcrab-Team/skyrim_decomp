// Source exposure: binary-analysis; no external implementation source reused.
// Static1782670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782670*);
    virtual void release(Static1782670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782670*);
struct Static1782670 {
    void* value;
    Static1782670();
    ~Static1782670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
