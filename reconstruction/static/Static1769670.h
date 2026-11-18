// Source exposure: binary-analysis; no external implementation source reused.
// Static1769670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769670*);
    virtual void release(Static1769670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769670*);
struct Static1769670 {
    void* value;
    Static1769670();
    ~Static1769670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
