// Source exposure: binary-analysis; no external implementation source reused.
// Static1766f60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766f60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766f60*);
    virtual void release(Static1766f60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766f60*);
struct Static1766f60 {
    void* value;
    Static1766f60();
    ~Static1766f60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
