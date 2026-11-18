// Source exposure: binary-analysis; no external implementation source reused.
// Static1787670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787670*);
    virtual void release(Static1787670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787670*);
struct Static1787670 {
    void* value;
    Static1787670();
    ~Static1787670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
