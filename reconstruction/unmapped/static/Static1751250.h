// Source exposure: binary-analysis; no external implementation source reused.
// Static1751250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751250*);
    virtual void release(Static1751250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751250*);
struct Static1751250 {
    void* value;
    Static1751250();
    ~Static1751250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
